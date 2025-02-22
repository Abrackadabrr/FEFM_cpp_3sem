#include <iostream>
#include "../type_deduction/deduce_type.hpp"


int main() {

    // Функции, объявленные внутри самого кода называются лямбда-функциями
    // Они всем похожи на функторы

    // Синтаксис
    // 1) внутри [] описывается то, что передается в СОСТОЯНИЕ лямбды
    // 2) внутри () описываются аргументы
    // 3) возвращаемое значение пишется через -> type, но это нам уже знакомо
    auto constant_multiplier = [](int a) -> int { return 10 * a; };
    auto print_int = [](int a) -> void { std::cout << a << std::endl; };

    // использование
    print_int(constant_multiplier(10));

    // угадаете тип, который вывел auto?
    deduce_type d0(print_int);
    deduce_type d1(constant_multiplier);
}

// Лямбда -- ну это почти как функтор, получается
// просто имеет немного другой синтаксис
