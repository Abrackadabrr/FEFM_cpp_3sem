#include <iostream>
#include <vector>

// реализовать "сборку" интерфейсов помогает механика множественного наследования

struct IMeasure {
    virtual double measure() = 0;
    virtual ~IMeasure() {}
};

struct IPerimeter {
    virtual double perimeter() = 0;
    virtual ~IPerimeter() {}
};

class Point {
    double x, y, z;
};

class Polygon : public IMeasure, public IPerimeter {
    std::vector<Point> points;

public:
    double measure() override {
        return 0;  // calculations over points
    }
    double perimeter() override {
        return 0;  // calculations over points
    }
};

int main() {
    Polygon p{};
    p.measure();

    // Polygon* теперь неявно приводится 
    // как к IMeasure*, так и к IPerimeter*
    Polygon* polygon_p = new Polygon{};
    IMeasure* i_measure_p = polygon_p;
    IPerimeter* i_perimeter_p = polygon_p;

    // был вопрос про то, 
    // совпадают ли указатели на базовый класс и на наследника
    // давайте посмотрим на адреса

    std::cout << "polygon_p = " << polygon_p << std::endl;
    std::cout << "i_measure_p = " << i_measure_p << std::endl;
    std::cout << "i_perimeter_p = " << i_perimeter_p << std::endl;
}

// это -- множественное наследование от классов-интерфейсов
// В каждом из базовых классов хранится указатель на свою таблицу виртуальных функций,
// и вроде как ничего не обчного тут нет. 
// Но это ощущение развеивается в момент, когда у базовых классов появляются поля.
