#include <iostream>
#include <vector>
#include <iterator>

// Что будет выведено в консоль?

int main() {
    auto it = std::vector{1, 2, 3, 4, 5, 6, 7}.begin();

    std::advance(it, 3);

    std::cout << *it << std::endl;

    std::advance(it, 8);

    std::cout << *it << std::endl;
}
