#include <cmath>

class Vector3d{
    double x, y, z;
    static const double epsilon = 1e-16;
public:
    Vector3d(double x_ = 0, double y_ = 0, double z_ = 0): 
    x(x_), y(y_), z(z_) {}

    bool equal(const Vector3d& rhs) const {
        return (std::abs(x - rhs.x) < epsilon) &&
            (std::abs(y - rhs.y) < epsilon) &&
            (std::abs(z - rhs.z) < epsilon);  
    }
};

bool operator==(const Vector3d& lhs, const Vector3d rhs) {
    return lhs.equal(rhs);
}

// аналогично оперделяются операторы >, >=, <, <=, !=