#include <vector>
#include <iostream>

// проблема: а как мне хранить логически почти одинаковые 
// объекты, которые все же являются разными типами?

struct Point {
    double x, y, z;
};

struct Vector3d{
    double x, y, z;
};

enum PolygonTypes {
    PENTAGON = 5,
    HEXAGON = 6
};

struct PolygonBasePart {
    std::vector<Point> points;  // реально необходимая информация
    // дополнительная информация, необходимая для осуществления единообразного хранения
    PolygonTypes type; 
    void * real_implementation;
};

// синтаксис публичного наследования следующий
// Hexagon содержит в себе экземпляр полигона

struct Hexagon {
    PolygonBasePart base_part;
    const static int number_of_vertex = 6;

    Hexagon(): base_part{std::vector<Point>{}, PolygonTypes::HEXAGON, this} {};
};

// Pentagon тоже содержит в себе экземпляр полигона
struct Pentagon {
    PolygonBasePart base_part;
    const static int number_of_vertex = 5;

    Pentagon(): base_part{std::vector<Point>{}, PolygonTypes::PENTAGON, this} {};
};


int main() {
    std::vector<PolygonBasePart*> flat_figures;
    flat_figures.reserve(10);

    for (int i = 0; i < 5; i++) {
        Pentagon* p_ptr = new Pentagon();
        flat_figures.push_back(&p_ptr->base_part);  
                                                               
        Hexagon* h_ptr = new Hexagon();
        flat_figures.push_back(&h_ptr->base_part);
    }

    // взял указатель на какую-то фигуру
    const PolygonBasePart* ptr_6 = flat_figures[6];
    // я могу узнать что это 
    std::cout << ptr_6->type << std::endl;
    // дальше я могу привести тип к необходимому мне и работать с этой фигурой как захочу
    const Pentagon* h_6 = static_cast<Pentagon*>(ptr_6->real_implementation);

    std::cout << h_6->number_of_vertex << std::endl;
}

// И теперь у меня получилось общее хранение РАЗНЫХ
// типов данных по одному и тому же указателю 
// на базовую часть. Удобно

// Но каждый раз писать одно и то же не хочется
// Такие добавили как механизм языка -- наследование
