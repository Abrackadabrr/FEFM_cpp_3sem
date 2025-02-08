// Для типов существует частичная специализация

#include <iostream>

// Primary template

template<typename F, typename S>
struct MyPair {
    F first;
    S second;

    MyPair() { std::cout << "<F, S>" << std::endl; }
};

// Частичная специализация -- это заплонение ЧАСТИ шаблонных параметров

template<typename T>
struct MyPair<T, T> {
    T fisrt;
    T second;

    MyPair() { std::cout << "<T, T>" << std::endl; }
};

template<typename T>
struct MyPair<T, int> {
    T first;
    int second;

    MyPair() { std::cout << "<T, int>" << std::endl; }
};

template<typename T>
struct MyPair<char, T> {
    char first;
    T second;

    MyPair() { std::cout << "<char, T>" << std::endl; }
};

// Здесь могут быть конфликты
// Анализируем код

int main() {
    // MyPair<double, float> p1{};
    // MyPair<double, double> p2{};
    // MyPair<float, float> p3{};
    // MyPair<char, float> p4{};
    // MyPair<double, int> p5{};
    // MyPair<int, int> p6{};
    // MyPair<char, char> p7{};
}
