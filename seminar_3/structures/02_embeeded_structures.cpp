#include <iostream>

// структуры можно использовать в качестве типа данных полей другой структуры, при этом сохраняется возможность создавать агругатную иничиацизацию

// точка в 3d
struct Point {
    double x1;
    double x2;
    double x3;
};

// сегмент в 3d
struct Segment {
    Point start;
    Point end;
};

int main() {
    
    // аргегатная инициализация для точки
    Point p1 = {0, 0, 0};
    Point p2 = {1, 1, 1};
    
    // агрегатная инициализация для сегмента
    Segment seg1 = {p1, p2};
    
    // тоже валидная агрегатная инициализация
    Segment seg2 = { {0, 0, 0}, {1,  1, 1} };

// смотрим на размер и выравнивание ради исследовательского интереса    
//    std::cout << sizeof(Point) << ' ' << alignof(Point) << std::endl;
//    std::cout << sizeof(Segment) << ' ' << alignof(Segment) << std::endl;

    return 0;
}
