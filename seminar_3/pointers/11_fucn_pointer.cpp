#include <iostream>

void incr (int * x_pointer) {
    (*x_pointer) ++;
    // *x_pointer = (*x_pointer) + 1;
}

void incr_1(int x) {
    x++;
}

int main ( ) {
    int x = 1;
    for (int i = 0; i < 3; i++) {
        incr(&x);
        std::cout << "x = " << x << std::endl;
    }
    return 0;
}
