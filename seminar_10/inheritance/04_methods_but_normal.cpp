#include <iostream>
#include <vector>

struct Polygon {
    // ключевое слово virtual показывает, что эта функция может быть перегружена 
    // в классах-наследниках 
    virtual double square() {
        std::cout << "complex alghoritm" << std::endl;
        return 0;
    }
    virtual double perimeter() {
        return 0;
    }
};

struct Hexagon : public Polygon {
    const static int number_of_vertex = 6;

    double square() {
        std::cout << "simple for hex" << std::endl;
        return 0;
    }
};

struct Pentagon : public Polygon {
    const static int number_of_vertex = 5;

    double square() {
        std::cout << "simple for pent" << std::endl;
        return 0;
    }
};

int main() {
    std::vector<Polygon*> flat_figures;
    flat_figures.reserve(10);

    for (int i = 0; i < 5; i++) {
        Pentagon* p_ptr = new Pentagon();
        flat_figures.push_back(static_cast<Polygon*>(p_ptr));  
        Hexagon* h_ptr = new Hexagon();
        flat_figures.push_back(h_ptr);
    }

    for (int i = 0; i < 10; i++) {
        flat_figures[i]->square();   
    }
}


// При создании класса с хотя бы одним виртуальным методом
// в этот класс добавляется указатель на таблицу виртуальных функций

// Конструктор базового класса выделяет динамически под неё память

// Консрукторы наследников инициализруют её нужными адресами
// Таким образом, получается правильно заполненная таблица виртуальных функций

// Это буквально то, что в примере 03 написано руками

// Конструирование таблицы виртуальных функций -- это ещё один
// аргумент в пользу того, что конструктор базового класса должен 
// быть вызван в первую очередь