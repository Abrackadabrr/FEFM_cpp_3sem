#include <iostream>

// Это функция с вычислением 
// целочисенного квадратного корня 
// от числа, написанная "обычно"

int isqrt_typical(int n) {
    unsigned long lb = 0;
    unsigned long ub = n;

    while (lb < ub) {
        unsigned long middle = (lb + ub + 1) / 2;
        if (n < middle * middle)
            ub = middle - 1;
        else 
            lb = middle;
    }
    return lb;
}

// Давайте перепишем её в функциональном стиле

int isqrt_impl(int n, int lb, int ub) {
    if (lb == ub)
        return lb;

    unsigned long middle = (lb + ub + 1) / 2;   
    if (n < middle * middle)
        return isqrt_impl(n, lb, middle - 1);
    else 
        return isqrt_impl(n, middle, ub);
}

int isrt_typical(int n) {
    return isqrt_impl(n, 0, n);
}

int main() {
    std::cout << isqrt_typical(26) << std::endl;
}

#if 0
int isqrt(int n, int lb, int ub) {
    if (lb == ub) 
        return ub;
    int middle = (lb + ub + 1) / 2;
    
    if (n < middle * middle)
        return isqrt(n, lb, middle - 1);
    else 
        return isqrt(n, middle, ub);
}

int isqrt(int n) {
    return isqrt(n, 1, n);
}
#endif 