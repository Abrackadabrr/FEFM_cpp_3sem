#include <iostream>


int main() {
    // оператор new на самом деле возращает нам указатель
    int *p = new int[10];
    std::cout << "Какие-то элементы " << p[0] << ' ' << p[1] << std::endl;
    std::cout << p << std::endl;
    std::cout << std::dec << (long)p << std::endl;
    return 0;
} 
