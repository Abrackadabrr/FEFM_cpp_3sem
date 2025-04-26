#include <iostream>
#include <omp.h>

// Директива single
// иполняет код только одним 
// потоком. Давайте узнаем каким

int main() {

#pragma omp parallel
{
    printf("Parallel\n");

    #pragma omp single
    {
        int rank = omp_get_thread_num();
        printf("Hello from %d\n", rank);
    } 
}
    printf("Parallel\n");
}
