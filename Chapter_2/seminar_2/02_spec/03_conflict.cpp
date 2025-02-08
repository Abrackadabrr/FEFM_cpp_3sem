#include <iostream>

template<typename T>
bool less(T lhs, T rhs) {
    return lhs < rhs;
}

int min(int a, int b) {
    less<int>(a, b) ? b : a;
}

template<>
bool less(int lhs, int rhs){
    std::cout << "lol" << std::endl;
    return true;
}

int main() {
    std::cout << less<int>(12, 2) << std::endl;
}

// Происходит конфликт специализации, написанной компилятором и руками, 
// из-за того, что написанная руками специализация ниже, чем требуется

// Если есть много функций, то есть и разрешение перегрузки
