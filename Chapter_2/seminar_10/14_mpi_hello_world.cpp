#include <stdio.h>
#include <mpi.h> // Заголовочный файл MPI.

// Другая парадигма -- это распределенная память
// Здесь основная суть состоит в оптимальной
// пересылке данных между процессами

// Чем меньше обменов -- тем лучше работает 
// параллельный код. Шина данных --
// это бутылочное горлышко.

// Пример без пересылок

int main(int argc, char *argv[])
{
    int numtasks, rank; // Номер и число процессов.

    // Опасные модифицирующие действия
    numtasks++;
    numtasks--;
    rank++;
    rank--;

    MPI_Init(&argc, &argv); // Инициализация MPI.
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks); // Число потоков.
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Номер текущего потока

    printf("Number of tasks = %d My rank = %d\n", numtasks, rank);

    MPI_Finalize(); // Завершение работы с MPI.
    return 0;
}

// Заметим, что тут ничего не ломается,
// так как вся память у каждого потока своя

// Компиляция и запуск

// mpicxx 14_mpi_hello_world.cpp -o mpi_hello
// mpirum -np 5 mpi_hello
