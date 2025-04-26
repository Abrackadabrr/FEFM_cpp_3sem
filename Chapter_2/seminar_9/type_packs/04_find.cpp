#include <iostream>
#include "print_type.hpp"

// Напишем метод find
// Что обычно возвращает алгоритм и метод find
// для стандартных контейнеров? 

template<typename ... Ts>
struct TypePack {
    template <typename T>
    constexpr static bool contains() noexcept {
    return (std::is_same_v<T, Ts> || ...);
    }

    template<typename T>
    constexpr static int find() noexcept {
        // чтобы написать этот метод
        // давайте подумаем, как мы бы
        // писали find для обычного
        // конетйнера
    } 

};

int main() {
    using TP1 = TypePack<int, double>;
    using TP2 = TypePack<char, bool>;

    std::cout << TP1::find<const char>() << std::endl;
}














#if 0

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

#endif