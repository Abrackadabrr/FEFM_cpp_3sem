#include <iostream>
#include <omp.h>

#include <unistd.h>

// Поток 0 берет четные итерации
// Поток 1 берет нечетные итерации

// Динамическое расписание для цикла for 
// позволяет сделать фактически thread pool

int main() {
    int N = 10;
 #pragma omp parallel for private(N) num_threads(2) schedule(dynamic, 1)
    for (int i = 0; i < 10; ++i) {
        int rank = omp_get_thread_num();
        N = i % 2;
        sleep(N);
#pragma omp critical
        std::cout << "Rank :" << rank << " Value N: " << N << std::endl;
    }
}
