#include <iostream>

// Расчет чисел Фибоначи на этапе компиляции

template<int N>
struct Fibonacci{
    static const unsigned long long value = (Fibonacci<N-1>::value + Fibonacci<N-2>::value);
};

template<>
struct Fibonacci<1> {
    static const unsigned long long value = 1;
};

template<>
struct Fibonacci<2> {
    static const unsigned long long value = 1;
};

unsigned long long fib(int N) {
    if (N <= 2) return 1;
    return fib(N-1) + fib(N-2);
}

int main() {
    std::cout << Fibonacci<50>::value << std::endl;
    std::cout << Fibonacci<45>::value << std::endl;
    std::cout << fib(50) << std::endl;
}
