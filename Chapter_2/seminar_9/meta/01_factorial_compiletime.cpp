#include <iostream>

// Что мы видим с вами в функциональном коде?


int fact_fun(int n) {
    // специализация для конкретного 
    // шаблонного параметра n = 0
    if (n == 0)
        return n;

    // primary template
    return n * fact_fun(n - 1);
}

template<int N>
struct factorial {
    static const int value = N * factorial<N-1>::value;
};

template<>
struct factorial<1> {
    static const int value = 1;
};

int main() {
    std::cout << factorial<5>::value << std::endl;
}

// Верно правило
// 1) Если параметры функции сравниваются
//    с какими-то конкретными значениями --
//    то это специальзация шаблоны
// 2) Остальное -- это primary template
// 3) Return == сохранить внутри себя static переменную

// Обычный цикл for переделывается в рекурсию
