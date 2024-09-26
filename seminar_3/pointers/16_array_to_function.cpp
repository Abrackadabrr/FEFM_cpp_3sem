#include <iostream>

struct X {
    int x1;
    int x2;
};

int main() {
    X *x_pointer = new X;
    (*x_pointer).x1 = 2;
    x_pointer->x1 = 23;
    std::cout << x_pointer->x1 << std::endl;
    delete x_pointer;
    return 0;
}
