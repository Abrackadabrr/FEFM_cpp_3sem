#include <iostream>
#include <vector>

// Есть специальная конструкция if constexpr,
// которая позволяет выбирать ветку исполнения
// на этапе компиляции

template<typename T>
int get_size(const T& value) {

    if constexpr (std::is_same_v<T, std::vector<int>>)
        return value.size();
    else 
        return sizeof(T);
}

int main() {
    std::cout << get_size(std::vector<int>{1, 2, 3, 4}) << std::endl;
    std::cout << get_size(5) << std::endl;
    std::cout << get_size(5.) << std::endl;
}

// Посмотрим на ... ассемблер
// с обычным if и if constexpr

// g++ 03_if_constexpr.cpp -S
