#include <iostream>

class Vector3d{
    double x, y, z;
public:
    Vector3d(double x_ = 0, double y_ = 0, double z_ = 0): 
    x(x_), y(y_), z(z_) {}
 
// работает с внутренним состоянием класса
    void dump(std::ostream& os) const {
        os << "(" << x << ", " 
        << y << ", " << z << ")" << std::endl;
    }
};

// не имеет доступа к внутреннему состоянию, 
// поэтому необходимо определение через метод dump

// либо можно сделать метод get на каждое поле и вызвать его здесь
std::ostream& operator<<(std::ostream& os, const Vector3d& v) {
    v.dump(os);
    return os;
}

// зачем возвращается ссылка на ostream?

int main() {
    Vector3d v{1, 1, 1};
    std::cout << v << std::endl;
}