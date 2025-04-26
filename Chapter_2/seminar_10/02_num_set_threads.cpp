#include <stdio.h>
#include <omp.h>

// Можно регулировать количество
// потоков исполнения

int main(int argc, char *argv[]) {

// можно функцией
omp_set_num_threads(2);
#pragma omp parallel
    {
    printf("Parallel region 1\n");
    }
// можно прагмой
#pragma omp parallel num_threads(3)
    {
        printf("Parallel region 2\n");
    }
// кто выиграет?
omp_set_num_threads(4);
#pragma omp parallel num_threads(1)
    {
        printf("Parallel region 3\n");
    }
}
