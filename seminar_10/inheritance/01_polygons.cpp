#include <vector>
#include <iostream>

struct Point {
    double x, y, z;
};

struct Vector3d{
    double x, y, z;
};

struct Polygon {
    std::vector<Point> points;

    bool getBorderOrientation() { return true; }

    Vector3d getNormal();

    // 

    // ... ect ... //
};

// Заведем классы правильных шести- и пятиугольника

// синтаксис публичного наследования следующий
// Hexagon содержит в себе экземпляр полигона

struct Hexagon : public Polygon {
    int number_of_vertex;

    double square();

    Hexagon(): Polygon(), number_of_vertex(6) {}
};

// Pentagon тоже содержит в себе экземпляр полигона
struct Pentagon : public Polygon {
    int number_of_vertex;

    double square();

    Pentagon(): Polygon(), number_of_vertex(5) {}
};

// обратите внимание на порядок вызовов конструкторов: 
// у нас всегда первым вызывается консруктор базового класса!!!

int main() {
    std::vector<Polygon*> flat_figures;
    flat_figures.reserve(10);

    for (int i = 0; i < 5; i++) {
        Pentagon* p_ptr = new Pentagon();
        flat_figures.push_back(static_cast<Polygon*>(p_ptr));  // тут можно и не писать static_cast, 
                                                               // просто будет работать неявное приведение типа
        Hexagon* h_ptr = new Hexagon();
        flat_figures.push_back(h_ptr);
    }

    // теперь я могу обращаться ко всем методам, которые оперделены в базовой части классов
    std::cout << flat_figures[0]->getBorderOrientation() << std::endl;
};

// то, что описано здесь -- это автоматическая 
// надстройка с указателями в примере 00_с_polygons.cpp