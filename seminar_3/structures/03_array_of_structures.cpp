#include <iostream>


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
    Point p_array[2] = {p1, p2};
    
    // тоже валидная агрегатная инициализация
    Segment seg2 = { {0, 0, 0}, {1,  1, 1} };

    // а теперь смотрим на массивы из структур
    Point points[] = { {0, 0, 1}, {0, 3, 4}, {0, 4, 5} };
    Segment segments[] = { { {0, 0, 1}, {0, 4, 6} } , { {0, 9, 5}, {0, 6, 7} } };
    std::cout << segments[1].end.x2 << std::endl;
    return 0;
}
