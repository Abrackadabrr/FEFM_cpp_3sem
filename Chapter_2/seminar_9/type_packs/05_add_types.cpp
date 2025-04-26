#include <iostream>
#include "print_type.hpp"
#include "print_type.cpp"

// Теперь я хочу уметь добавлять слева и 
// справа произвольное число типов

// Буду ли я писать функцию?

template<typename ... Ts>
struct TypePack {
    template<typename ... Ts1>
    using add_right = TypePack<Ts ..., Ts1 ...>;

    template<typename ... Ts1>
    using add_left = TypePack<Ts1 ..., Ts ...>;
};

int main() {
    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;

    std::cout << type_name<TP1::add_left<bool, char>>() << std::endl;
}
