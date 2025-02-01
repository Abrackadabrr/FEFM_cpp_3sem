#include <omp.h>
#include <iostream>

int main() {

#pragma omp parallel num_threads(14)
{
	int rank = omp_get_thread_num();
#pragma omp critical 
	{
	std::cout << "Hello, Wolld! With love from Thread #" << rank << std::endl;
	}
}
	return 0;
}
