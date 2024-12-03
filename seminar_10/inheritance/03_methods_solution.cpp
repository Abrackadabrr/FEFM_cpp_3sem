#include <iostream>
#include <vector>

enum PolygonTypes {
    PENTAGON = 5,
    HEXAGON = 6
};

class Hexagon;
class Pentagon;

struct Polygon {
    // добавляем вспомогательную информацию снова
    PolygonTypes type; 
    void * real_implementation;
    // эти строчки у нас уже были

    // а вот эти штуки новые
    using h_square_ptr_t = double (Hexagon::*)() const;
    using p_square_ptr_t = double (Pentagon::*)() const;

    h_square_ptr_t h_function_pointer;
    p_square_ptr_t p_function_pointer;

    // ---- //

    double square() const;
};


struct Hexagon {
    Polygon base_part;
    const static int number_of_vertex = 6;

    double square() const {
        std::cout << "simple for hex" << std::endl;
        return 0;
    }

    Hexagon(): base_part{PolygonTypes::HEXAGON, this, &Hexagon::square, nullptr} {};
};

struct Pentagon {
    Polygon base_part;
    const static int number_of_vertex = 5;


    double square() const {
        std::cout << "simple for pent" << std::endl;
        return 0;
    }

    Pentagon(): base_part{PolygonTypes::PENTAGON, this, nullptr, &Pentagon::square} {};
};


double Polygon::square() const{
        if (type == HEXAGON) {
            Hexagon* h_ptr = static_cast<Hexagon*>(real_implementation);
            return (h_ptr->*h_function_pointer)();
        }
        if (type == PENTAGON) {
            Pentagon* p_ptr = static_cast<Pentagon*>(real_implementation);
            return (p_ptr->*p_function_pointer)();
        }

        std::cout << "complex alghoritm" << std::endl;
        return 0;
    }

int main() {
    std::vector<Polygon*> flat_figures;
    flat_figures.reserve(10);

    for (int i = 0; i < 5; i++) {
        Pentagon* p_ptr = new Pentagon();
        flat_figures.push_back(&p_ptr->base_part);  
                                                               
        Hexagon* h_ptr = new Hexagon();
        flat_figures.push_back(&h_ptr->base_part);
    }

    for (int i = 0; i < 10; i++) {
        // я хочу, чтобы тут каким-то образом вызывался 
        // метод правильного класса (Hexagon или Pentagon)
        // а не общий метод sqaure в типе Polygon
        flat_figures[i]->square();

    }
}

// для того, чтобы не городить такой огромный забор кода
// мы будет просто пользоваться механизмом виртуальных функций