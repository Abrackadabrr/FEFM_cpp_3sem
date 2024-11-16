#include <iostream>
#include <vector>

struct Polygon {
    double square() {
        std::cout << "complex alghoritm" << std::endl;
        // большая сложная реализация метода вычисления площади 
        // для произвольных плоских многоугольников
        return 0;
    }
};

struct Hexagon : public Polygon {
    const static int number_of_vertex = 6;

    // а тут метод sqaure был бы в разы проще -- просто длина стороны * const
};

// Pentagon тоже содержит в себе экземпляр полигона
struct Pentagon : public Polygon {
    const static int number_of_vertex = 5;

    // а тут метод sqaure был бы в разы проще -- просто длина стороны * const
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
        flat_figures[i]->square();   // хочется дописать "хорошие" методы
        // в классы hexagon и polygon и сделать так, чтобы 
        // метод square как-то различал, что именно нужно вызвать
    }
}