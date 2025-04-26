#include <iostream>
#include "print_type.hpp"
#include "print_type.cpp"

// Метод, который пишет типы в std::cout
 
template<typename ... Ts>
struct TypePack {
    template<typename ... Ts1>
    using add_right = TypePack<Ts ..., Ts1 ...>;

    template<typename ... Ts1>
    using add_left = TypePack<Ts1 ..., Ts ...>;

    static void print() {
       // ???
    }
};


int main() {
    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;

    TP1::add_left<bool, char>::print();
}

// Можно ли print сделать constexpr?



#if 0

    static void print() {
        (std::cout << ... << type_name<Ts>()) << std::endl;
    }

#endif