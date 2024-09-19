#include <iostream>

int plus_10(int a) {
    int c = 10;
    a += c;
    return a;
}

int main() {
    int b = 0;
    std::cout << plus_10(b) << std::endl;
    a = 0; c += 10; // это ошибка компиляции, потому что а -- это локальная переменная функции plus_10, она существует только в теле этой функции
    
}
