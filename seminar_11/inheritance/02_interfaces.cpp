#include <iostream>
#include <vector>

// ещё мы говорили про интерфейсы

struct IMeasure {
    virtual double measure() = 0;
};

struct IPerimeter {
    virtual double perimeter() = 0;
};

class Point;

class Polygon : public IMeasure {
    std::vector<Point> points;

public:
    double measure() override {
        return 0;  // calculations over points
    }
};
// кстати, кто видит ошибку в реализации классов?


// логически должен ли Polygon иметь метод perimeter?


// предложите объекты, которые логически могут содержать
// measure и не содержать perimeter?
