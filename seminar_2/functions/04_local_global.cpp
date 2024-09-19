#include <iostream>

int power(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

int main() {
    // локальные переменные функции main
    // они "видны" только в этой функции
    int x = 2;
    int n = 5;
    int res = power(x, n);

    // вывод значения локальной переменной res на экран
    std::cout << res << std::endl;
    return 0;
}
