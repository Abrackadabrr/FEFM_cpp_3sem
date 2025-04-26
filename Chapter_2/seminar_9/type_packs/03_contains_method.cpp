#include <iostream>
#include "print_type.hpp"

// Завернули contains в метод

template<typename ... Ts>
struct TypePack {
    template <typename T>
    constexpr static bool contains() noexcept {
    return (std::is_same_v<T, Ts> || ...);
}
};

int main() {

    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;
    
    if constexpr(TP1::contains<int>())
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;

    if constexpr(TP2::contains<int>())
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;
}
