#include <iostream>

// это пример на то, как компилятор определяет, какую переменную из имеющегося набора выбрать для использования

const int a = 2;

void print_a_n_times(int a, int n) {
    for (int i = 0; i < n; i++) {
        int a = 3;
        std::cout << a << ' ';
    }
    std::cout << a << std::endl;
}

int main() {
    int a = 1;
    std::cout << "Local main var a: " << a << std::endl;
    int n = 10;
    print_a_n_times(a, n);
    return 0;    
}


// компилятор ввсегда выбирает ближайшую переменную 
