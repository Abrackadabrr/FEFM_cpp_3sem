#include <vector>

// Можно создавать шаблоны пользовательских типов данных

class Point2DOld{
    double x, y;
};

// А теперь сделаем класс шаблонным
template<typename T>
class Point {
    T x, y;
};


// Теперь Point -- это обобщённый класс точки на плоскости, позволяющий хранить в себе 
// координаты любых типов (int, double, string)


int main() {
    Point<double> p1;
    Point<int> p2;
    Point<short> p3;
    Point<double> p4;
    // и так далее сколько угодно типов можно писать
    Point<std::vector<std::vector<double>>> p5{};  // без комментариев...
}
