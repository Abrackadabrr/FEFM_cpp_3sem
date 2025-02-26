#include <iostream>
#include <cmath>
#include <vector>

#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkStructuredGrid.h>
#include <vtkSmartPointer.h>

#include <random>

using namespace std;

// Класс расчётной точки
class CalcNode
{
// Класс сетки будет friend-ом точки
friend class CalcMesh;

protected:
    // Координаты
    double x;
    double y;
    double z;
    // Некая величина, в попугаях
    double smth;
    // Скорость
    double vx;
    double vy;
    double vz;

public:
    // Конструктор по умолчанию
    CalcNode() : x(0.0), y(0.0), z(0.0), smth(0.0), vx(0.0), vy(0.0), vz(0.0)
    {
    }

    // Конструктор с указанием всех параметров
    CalcNode(double x, double y, double z, double smth, double vx, double vy, double vz) 
            : x(x), y(y), z(z), smth(smth), vx(vx), vy(vy), vz(vz)
    {
    }

    // Метод отвечает за перемещение точки
    // Движемся время tau из текущего положения с текущей скоростью
    void move(double tau1, double tau2, double tau3) {
        x += vx * tau1;
        y += vy * tau2;
        z += vz * tau3;
    }
};

// Класс расчётной сетки
class CalcMesh
{
protected:
    // 2D-сетка из расчётных точек
    vector<vector<CalcNode>> points;

public:
    // Конструктор сетки size x size точек с шагом h по пространству
    CalcMesh(unsigned int size, double h) {
    
        std::random_device dev;
    	std::mt19937 rng(dev());
    	std::uniform_int_distribution<std::mt19937::result_type> dist6(0,2); // distribution in range [1, 6]
    
        points.resize(size);
        for(unsigned int i = 0; i < size; i++) {
            points[i].resize(size);
            for(unsigned int j = 0; j < size; j++) {
                // Начальные координаты зададим равномерно в плоскости OXY
                double pointX = i * h;
                double pointY = j * h;
                double pointZ = 0;
                // Модельная скалярная величина распределена как-то вот так
                double smth = pow(pointX, 2) + pow(pointY, 2);
                // Профиль скорости по Z тоже взят какой-нибудь с потолка
                double vz = pow(pointX - pointY, 2);

                points[i][j] = CalcNode(pointX, pointY, pointZ, smth, dist6(rng)/50., dist6(rng)/50., vz);
            }
        }
    }

    // Метод отвечает за выполнение для всей сетки шага по времени величиной tau
    void doTimeStep(double tau1, double tau2, double tau3) {
        // По сути метод просто двигает все точки
        for(unsigned int i = 0; i < points.size(); i++) {
            for(unsigned int j = 0; j < points[i].size(); j++) {
                points[i][j].move(tau1, tau2, tau3);
            }
        }
    }

    // Метод отвечает за запись текущего состояния сетки в снапшот в формате VTK
    void snapshot(unsigned int snap_number) {
        // Сетка в терминах VTK
        vtkSmartPointer<vtkStructuredGrid> structuredGrid = vtkSmartPointer<vtkStructuredGrid>::New();
        // Точки сетки в терминах VTK
        vtkSmartPointer<vtkPoints> dumpPoints = vtkSmartPointer<vtkPoints>::New();

        // Скалярное поле на точках сетки
        auto smth = vtkSmartPointer<vtkDoubleArray>::New();
        smth->SetName("smth");

        // Векторное поле на точках сетки
        auto vel = vtkSmartPointer<vtkDoubleArray>::New();
        vel->SetName("velocity");
        vel->SetNumberOfComponents(3);

        // Обходим все точки нашей расчётной сетки
        unsigned int number = (unsigned int)points.size();
        for(unsigned int i = 0; i < number; i++) {
            for(unsigned int j = 0; j < number; j++) {
                // Вставляем новую точку в сетку VTK-снапшота
                dumpPoints->InsertNextPoint(points[i][j].x, points[i][j].y, points[i][j].z);

                // Добавляем значение векторного поля в этой точке
                double _vel[3] = {points[i][j].vx, points[i][j].vy, points[i][j].vz};
                vel->InsertNextTuple(_vel);

                // И значение скалярного поля тоже
                smth->InsertNextValue(points[i][j].smth);
            }
        }

        // Задаём размеры VTK-сетки (в точках, по трём осям)
        structuredGrid->SetDimensions(number, number, 1);
        // Грузим точки в сетку
        structuredGrid->SetPoints(dumpPoints);

        // Присоединяем векторное и скалярное поля к точкам
        structuredGrid->GetPointData()->AddArray(vel);
        structuredGrid->GetPointData()->AddArray(smth);

        // Создаём снапшот в файле с заданным именем
        string fileName = "cubic2d-step-" + std::to_string(snap_number) + ".vts";
        vtkSmartPointer<vtkXMLStructuredGridWriter> writer = vtkSmartPointer<vtkXMLStructuredGridWriter>::New();
        writer->SetFileName(fileName.c_str());
        writer->SetInputData(structuredGrid);
        writer->Write();
    }
};

int main()
{
    // Размер расчётной сетки, точек на сторону
    unsigned int size = 10;
    // Шаг точек по пространству
    double h = 0.1;
    // Шаг по времени
    double tau = 0.01;

    // Создаём сетку заданного размера
    CalcMesh mesh(size, h);

    // Пишем её начальное состояние в VTK
    mesh.snapshot(0);
    
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,3); // distribution in range [1, 6]


    // Делаем шаги по времени, 
    // на каждом шаге считаем новое состояние и пишем его в VTK
    for(unsigned int step = 1; step < 100; step++) {
        mesh.doTimeStep(tau * dist6(rng), tau * dist6(rng), tau * dist6(rng));
        mesh.snapshot(step);
    }

    return 0;
}
