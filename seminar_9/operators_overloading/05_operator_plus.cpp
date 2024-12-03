struct Vector3d {
    double x, y, z;

    Vector3d& operator+=(const Vector3d& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector3d operator+(const Vector3d& rhs) const {
        Vector3d tmp{*this};
        tmp+=rhs;
        return tmp;
    }
};

int main() {
    Vector3d v1{0, 0, 1};
    Vector3d v2{0, 1, 0};

    Vector3d v3 = v1 + v2;
}

// такое оперделение оператора несимметрично
// давайте посмотрим на приведение типов