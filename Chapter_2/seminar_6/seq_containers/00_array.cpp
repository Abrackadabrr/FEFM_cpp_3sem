#include <array>
#include <iostream>
#include <algorithm>

// std::array<T, N> -- это обёртка над 
// статическим массивом T[N]

int main() {
    std::array a{1, 2, 3, 4, 5};
    std::cout << a[0] << std::endl;
    std::cout << a.at(0) << std::endl;

    // В чем разница между методом at() и []?

    auto it = std::find(a.begin(), a.end(), 5);
    std::cout << *it << std::endl;

    // Как вы думаете, какой должен быть iterator_category,
    // чтобы использовать в алгоритме std::find?

    // Как вы думаете, что такое iterator_type для std::array?
}
