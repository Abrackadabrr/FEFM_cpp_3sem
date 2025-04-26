#include <iostream>
#include <omp.h>

// Простейший пример параллельной программы: 
// вывод какой-то фразы на экран

int main(int argc, char *argv[])
{
    std::cout <<  "Master thread: hello\n";
#pragma omp parallel
{
//    int rank = omp_get_thread_num();
    std::cout <<  "Hello from thread #\n"; // << rank << std::endl;
}
    std::cout <<  "Master thread: hello again\n";
    return 0;
}


// А теперь пробуем раскомментировать 
// куски кода: что изменится?
