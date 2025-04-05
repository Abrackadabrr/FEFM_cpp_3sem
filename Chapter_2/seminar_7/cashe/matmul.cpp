#include <iostream>
#include <vector>
#include <chrono>

template<typename T>
void matmul_v0(int M, int N, int K, const T * A, const T * B, T * C)
{
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < K; ++k)
                C[i*N + j] += A[i*K + k] * B[k*N + j];
        }
    }
}

int main(int argc, char **argv) {
   size_t n = atoi(argv[1]);
   std::vector<double> A(n * n), B(n * n);
   for (size_t i = 0; i < n; ++i) {
     for (size_t j = 0; j < n; ++j) {
       A[n * i + j] = i + j;
       B[n * i + j] = i + j;
     }
   }
   std::vector<double> res; res.resize(n * n);

   auto start = std::chrono::steady_clock::now();

   // execution
   matmul_v0(n, n, n, A.data(), B.data(), res.data()); 

   auto end = std::chrono::steady_clock::now();
   auto dur = std::chrono::duration<double>(end - start);
   std::cout << dur.count() << std::endl;

}