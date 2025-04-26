#include <iostream>
#include <mpi.h>
#include <omp.h>
#include <unistd.h>


// Простейший пример совместной работы 
// MPI и OpenMP в программе 

int main(int argc, char *argv[]) {
    
    MPI_Init(&argc, &argv);
    int rank, count;
    std::string buf; 
    buf.reserve(100);
    MPI_Status status;   // вспомогательная штука для метаданных 
                         // пересылки

    // Вытаскиваем ранг потока
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        buf = "Hello from 0";
        std::cout <<"I send to the rank 1 message \""<< buf << "\"" << std::endl;
        MPI_Send(buf.data(),       // откуда шлём
                 buf.length() + 1, // сколько шлём
                 MPI_CHAR,         // тип данных
                 1,                // кому шлём 
                 99,               // какой тэг у сообщения 
                 MPI_COMM_WORLD);  // в каком коммуникторе коммуницируем
        buf = "Empty...";
    } else if (rank == 1) {
        MPI_Recv(const_cast<char*>(buf.data()),  // куда принимаем
                100,        // сколько принимаем
                MPI_CHAR,   // какой тип принимаем
                MPI_ANY_SOURCE, // от кого принимаем
                MPI_ANY_TAG,    // какое именно сообщение принимаем (тэг)
                MPI_COMM_WORLD, // в каком коммуникаторе коммуницируем
                &status);       // куда пишем метаданные

        MPI_Get_count(&status, MPI_CHAR, &count);
        printf("Message ’%s’, from %d, tag %d, size %d\n", 
                buf.data(), status.MPI_SOURCE, status.MPI_TAG, count);
    }

#pragma omp parallel for 
    for (int i = 0; i < 5; i++) {
        sleep(2);
        int rank_omp = omp_get_thread_num();
        printf("Hello from rank (%d, %d) with message \"%s\"\n", rank, rank_omp, buf.data() + i);
    }

    MPI_Finalize();
}

// mpicxx 16_hybrid.cpp -o hybrid -fopenmp
// mpirun -np 2 hybrid
