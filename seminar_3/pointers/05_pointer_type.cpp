#include <iostream>

// указатель -- это тоже тип данный, и переменные этого типа как-то записаны в память, давайте посмотрим как 

int main() {
    std::cout << sizeof(int *) << std::endl;
    std::cout << sizeof(double *) << std::endl;
    std::cout << sizeof(float *) << std::endl;
    std::cout << sizeof(char *) << std::endl;
    std::cout << sizeof(bool *) << std::endl;
    std::cout << std::hex << UINTPTR_MAX << std::endl;
    return 0;
}

