#include <iostream>

struct Vector3d {
    double x, y, z;

// цепочечный оператор вида (operator)=
// возвращает ссылку на свое состояние
    Vector3d& operator+=(const Vector3d& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
};

int main() {
    // цепочечные операторы вида +=, -=, *=, /= являются правоассоциативными
    int a = 7;
    int b = 3;
    int c = 6;
    a -= b *= c /= 3; // что в а?
    std::cout << a << std::endl;

    // аналогично и с пользоватлеьскими типами
    Vector3d v1{1, 0, 0};
    Vector3d v2{0, 1, 0};
    Vector3d v3{0, 0, 1};
    Vector3d v4 = v3 += v2 += v1;
};
