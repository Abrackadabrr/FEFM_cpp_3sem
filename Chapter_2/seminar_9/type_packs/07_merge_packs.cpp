#include <iostream>
#include "print_type.hpp"
#include "print_type.cpp"


template<typename ... Ts>
struct TypePack {
    template <typename T>
    constexpr static bool contains() noexcept {
    return (std::is_same_v<T, Ts> || ...);
    }

    template<typename T>
    constexpr static int find() noexcept {
        constexpr bool is_same[sizeof...(Ts)] = {std::is_same_v<T, Ts>...};
        for (std::size_t i = 0; i < sizeof...(Ts); ++i) {
            if (is_same[i]) {
                return i;
            }
        }
        return sizeof...(Ts);
    } 

    template<typename ... Ts1>
    using add_right = TypePack<Ts ..., Ts1 ...>;

    template<typename ... Ts1>
    using add_left = TypePack<Ts1 ..., Ts ...>;
};


// Давайте напишем merge_packs 
// Для произвольного количества паков
// Будет ли это функция?


// Напишем для двух паков

template<typename P1, typename P2>
using merge_packs = // ???;

int main() {
    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;

    std::cout << type_name<merge_packs<TP1, TP2>>() << std::endl;
}



#if 0

template<typename... Ts1, typename... Ts2>
constexpr TypePack<Ts1..., Ts2...> operator+(TypePack<Ts1...>, TypePack<Ts2...>) noexcept {
    return {};
}


template<typename P1, typename P2>
using merge_packs = decltype(P1{} + P2{});

#endif