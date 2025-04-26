#include <iostream>

int main() {
    int value = 0;
    int N = 1e6;

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        // some stuff
        value++;
    }
    std::cout << value << std::endl;
}

// Какой результат в value?










// А если подумать?
