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

int fibonnachi(int n){
    if (n < 2) 
        return 1;
    int x, y;
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            x = fibonnachi(n - 1);
            #pragma omp section
            y = fibonnachi(n - 2);
        }
    }
    return x + y;
}

int main() {
    int n = 42;
    omp_set_nested(1);
    int nt = omp_get_max_threads();
    std::cout << "Max num threads = " << nt << std::endl; 
    std::cout << "Fork bomb exploding..." << std::endl;
    std::cout << fibonnachi(n) << std::endl;
    return 0;
}
