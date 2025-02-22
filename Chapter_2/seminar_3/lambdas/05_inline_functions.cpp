#include <iostream>

// inline -- это указание для компилятора
// "пожалуйста тело функции вставь вместо вызова"
// "invoke this fucntion in line"

inline bool less(int rhs, int lhs) {
    return rhs < lhs;
}

int main() {
    int a = 5, b = 4;
    std::cout << less(a, b) << std::endl;
}
