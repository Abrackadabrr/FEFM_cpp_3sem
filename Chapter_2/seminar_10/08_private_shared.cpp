#include <iostream>
#include <omp.h>

int main() {
    // Представим, что здесь очень сложная 
    // функция, которая считает и выдает результат 
    
    // ...
    
    // int N = 10;
    int N = 10;

    // Дальше внутри for мне нужно её модифицирвоать
    // и я распараллеливаю цикл 
#pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        int rank = omp_get_thread_num();
        N = rank;
#pragma omp critical
        std::cout << "Rank :" << rank << " Value N: " << N << std::endl;
    }
}

// Как полечить этот кусок кода?
// Каждый потом хочет пользоваться
// Переменной N
