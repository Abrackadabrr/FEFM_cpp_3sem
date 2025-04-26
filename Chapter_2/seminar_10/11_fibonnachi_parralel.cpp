#include <iostream>
#include <omp.h>

int fib(int n) {
    unsigned long first = 0, second = 1, next;

    for (int i = 2; i < n; ++i) {
        next = first + second;
        first = second;
        second = next;
    }
    
    return second;
}

int fibonnachi(int n, int nt) { 
    if (n < 2) 
        return 1;
    if (nt < 2) 
        return fib(n);
    int x, y;
    #pragma omp parallel // num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            x = fibonnachi(n - 1, nt / 2);
            #pragma omp section
            y = fibonnachi(n - 2, nt - nt / 2);
        }
    }
    return x + y;
}

int main() {
    int n = 42;
    omp_set_nested(1);
    int nt = omp_get_max_threads();
    std::cout << "Max num threads = " << nt << std::endl; 
    std::cout << fibonnachi(n, 16) << std::endl;
    return 0;
}


// Давайте заметим, что функции
// 
// x = fibonnachi(n - 1, nt / 2);
// y = fibonnachi(n - 2, nt - nt / 2);
//
// различаются по времени исполнения в два раза.
// Давайте посмотрим на это чуть лучше
// 
// Это потенциальная проблема, так как
// время исполнения -- это как минимум 
// время исполнения самого долгого куска
