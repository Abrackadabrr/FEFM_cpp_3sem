#include <iostream>

// Задача следующая: 
// нужно написать контейнер для типов

template<typename ... Types>
struct TypePack {};

// Что будет хранить в себе структура?

using integral_pack = TypePack<char, short, int, unsigned, long, unsigned long>;

int main() {
    // std::cout <<  << std::endl;
}
