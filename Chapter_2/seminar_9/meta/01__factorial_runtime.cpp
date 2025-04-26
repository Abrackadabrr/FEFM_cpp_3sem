#include <iostream>

// Давайте посмотрим на то как 
// можно решать задачки о переводе 
// рантайм программ в программы 
// времени компиляции


int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
} 

// Давайте нашем этот код без использования
// циклов, чисто в функциональном стиле

int fact_fun(int n) {
    if (n == 1)
        return 1;
    return n * fact_fun(n - 1);
}

// Теперь рекурсия стала более явной

int main() {
    std::cout << fact_fun(5) << std::endl;
}

