#include <iostream>

const int GLOBAL_INT = 3;

int get_global_int() {
    return GLOBAL_INT;
}


int get_global_a() {
    return a;
}

const int a = 0;

int main() {
    std::cout << GLOBAL_INT << std::endl;
    std::cout << get_global_a() << std::endl;
}

