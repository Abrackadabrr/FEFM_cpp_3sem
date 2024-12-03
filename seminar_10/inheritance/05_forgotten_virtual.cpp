#include <iostream>
#include <vector>

struct Polygon {
    virtual double square() {
        std::cout << "complex alghoritm" << std::endl;
        return 0;
    }
};

struct Hexagon : public Polygon {
    const static int number_of_vertex = 6;
};

struct Pentagon : public Polygon {
    const static int number_of_vertex = 5;

    double square() {
        std::cout << "simple for pent" << std::endl;
        return 0;
    }
};


// забыли virtual -- что будет на экране?
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