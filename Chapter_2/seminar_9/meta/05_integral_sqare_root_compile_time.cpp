#include <iostream>
#include <utility>


int isqrt(int n, int lb, int ub) {
    // специализация при равенстве 
    // верхней и нижней границ
    if (lb == ub) 
        return ub;
    // это тоже шаблонный параметр, так как он явно зависим 
    // от аргументов функции
    int middle = (lb + ub + 1) / 2;
    
    // это conditional_t
    if (n < middle * middle)
        return isqrt(n, lb, middle - 1);  // это рекрусивное
                                          // инстанцирование
    else 
        return isqrt(n, middle, ub); // это рекрусивное
                                     // инстанцирование
}


template <int N, 
          int L = 1, 
          int H = N, 
          int mid = (L + H + 1) / 2>
struct Sqrt {
    static const int value = std::conditional_t<(N < mid * mid), Sqrt<N, L, mid - 1>,
                                          Sqrt<N, mid, H>>::value;
};

template <int N, int S>
struct Sqrt<N, S, S> {
    static const int value = S;
};

int main() { 
    std::cout << Sqrt<26>::value << std::endl; 
}
