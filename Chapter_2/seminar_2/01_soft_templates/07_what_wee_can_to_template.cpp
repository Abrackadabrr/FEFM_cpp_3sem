#include <vector>
#include <iostream>

// Что в принципе можно зашаблонить?

// функция
template<typename T>
T foo(T x) {return T{};};

// пользовательский тип
template<typename T>
class Pointer {
    T* ptr;
};

// using (alias)
template<typename T>
using double_vector = std::vector<std::vector<T>>;

// переменную
template<typename T>
const T PI = 3.141592653589;

int main() {
    std::cout.precision(16);

// Разные типы данных для переменной
    std::cout << PI<float> << std::endl;
    std::cout << PI<double> << std::endl;
}

// То, что стоит внутри < >, называется шаблонными параметрами
