#include <iostream>

int main() {
#pragma omp parallel
{
    int n = 1;
#pragma omp master
    n=2;
    printf("n: %d\n", n);
}
}

// Заметим, что мастер поток
// приходит не всегда в одно и то же 
// время к выводу на экран

// "Последовательность" выполнения
// нитей недетерминирована
