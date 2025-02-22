#include <iostream>

template<typename T>
T max(T rhs, T lhs) {
    return rhs > lhs ? rhs : lhs;
}

int main() {
    std::cout << max<int>(3, 4) << std::endl;
    std::cout << max(4, 5) << std::endl;
    return 0;
}

// Если не указывать тип внутри треугольных скобочек, 
// то он будет выведен компилятором самостоятельно
