struct Vector3d {
    double x, y, z;

    Vector3d(double x_ = 0, double y_ = 0, double z_ = 0): 
    x(x_), y(y_), z(z_) {}
    //  задает неявное преобразование типа double в тип Vectro3d, 
    // так как может быть вызван от ондого аргумента

    Vector3d& operator+=(const Vector3d& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
};

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs) {
    Vector3d tmp{lhs};
    tmp+=rhs;
    return tmp;
};

int main() {
    Vector3d v1{0, 0, 1};
    Vector3d v2{0, 1, 0};

// тут случится неявное преобразование 2 к v1
    Vector3d v3 = v2 + 1;
// и тут теперь тоже
    v3 = 1 + v2;
};