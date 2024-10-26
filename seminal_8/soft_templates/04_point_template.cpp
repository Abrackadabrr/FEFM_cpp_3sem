// Можно создавать шаблоны пользовательских типов данных

class Point2DOld{
    double x, y;
};

// Это несравненно удобнее
template<typename T>
class Point {
    T x, y;
};


// Теперь Point -- это обобщённый класс точки на плоскости, позволяющий хранить в себе 
// координаты любых типов (int, double, string, MyStructure (???))


int main() {
    Point<double> p1;
    Point<int> p1;
    Point<short> p1;
    Point<double> p1;
    // и так далее сколько угодно типов можно писать
}
