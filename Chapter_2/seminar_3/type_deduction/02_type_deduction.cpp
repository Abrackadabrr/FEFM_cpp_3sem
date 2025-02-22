// Попробуем угадать, что сработает, а что нет

#include <iostream>
#include <string>

template<typename T>
T maximum(T rhs, T lhs) {
    return rhs > lhs ? rhs : lhs;
}

int main() {
    std::cout << maximum(3, 4) << std::endl;
    // std::cout << maximum(4, 5.) << std::endl;
    // std::cout << maximum(5., 6.) << std::endl;
    // std::cout << maximum(static_cast<short>(5), 6) << std::endl;

    std::string s1{"Hello"};
    std::string s2{"World"};
    // std::cout << maximum(s1, s2) << std::endl;
    // std::cout << maximum(s1, "Hello") << std::endl;
    // std::cout << maximum("Hello", "World") << std::endl;
    return 0;
}

// Получается, что иногда комплятор так разрешает типы, 
// как нам не хотелось бы 