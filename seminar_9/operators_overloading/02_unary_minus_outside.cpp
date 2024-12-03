struct Vector3d {
    double x, y, z;
};

// операторы можно оперделить и вне класса

Vector3d operator-(const Vector3d& v) {
    return Vector3d{-v.x, -v.y, -v.z};
}

int main() {
    Vector3d v1{1, 1, 1};
    Vector3d v2 = -v1;
}

// резульат применения будет абсолютно такой же