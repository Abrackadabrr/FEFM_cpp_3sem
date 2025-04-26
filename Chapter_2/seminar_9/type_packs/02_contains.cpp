// Попробуем узнать, есть ли 
// тип в данной пачке типов

#include <iostream>
#include "print_type.hpp"

// Давайте сделаем это отдельной функцией

template<typename ... Types>
struct TypePack {};

constexpr bool contains() {
    // ???
}

int main() {

    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;
    
    if constexpr(contains<int>(TP2{}))
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;

}

// Есть ли критика подхода "отдельной функции"


#if 0

template <typename T, typename... Ts>
constexpr bool contains(const TypePack<Ts...>& pack) noexcept {
    return (std::is_same_v<T, Ts> || ...);
}

#endif