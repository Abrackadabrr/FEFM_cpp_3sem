#include <iostream>

// Задача: давайте сделаем что-нибудь, что на этапе
// компиляции сможет вычислить нам квадрат целого числа
// Допустим, с помощью этого мы будем вычислять
// размера статического массива

template<int N>
struct square {
    static const int value = N * N;
};

int main() {
    int array[square<5>::value] = {1, 2, 3, 4, 5};
}
