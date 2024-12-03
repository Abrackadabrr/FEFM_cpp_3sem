#include <iostream>
#include <ostream>

class A {
    int a = 0;
    int b = 1;
public:
    void print(std::ostream& os) const {
        os << "Instance of class A: " << a << " & " << b << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const A& rhs) {
    rhs.print(os);
    return os;
}

int main() {
    A a{};
    std::cout << a << std::endl;
}
