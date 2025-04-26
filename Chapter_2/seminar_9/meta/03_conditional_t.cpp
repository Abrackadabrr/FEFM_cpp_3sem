#include <iostream>

// Для работы с if statements
// нам нужен будет шаблонный if
// это есть consitional.

// Conditional обображает значение
// {true, false} на типы {T, F}

template<bool v, typename T, typename F>
struct conditional {
    using type = T;
};

template<typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

template<bool v, typename T, typename F>
using cond_t = conditional<v, T, F>::type;

template<bool v>
using get_type = cond_t<v, int, double>;

int main() {
    std::cout << sizeof(get_type<(0 > 1)>) << std::endl;
    std::cout << sizeof(get_type<((1 + 10) && 0)>) << std::endl;
}

// Таким образом я на этапе компляции могу 
// заифать выбор типа из пары
