// Итераторы так же могу различаться 
// по направлению и по константности


#include <vector>
#include <iostream>

int main() {
    std::vector v{1, 2, 3, 4, 5, 6, 7};

    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << std::endl;
    }
    // check cppinsights
    std::cout << " // ---------------- //" << std::endl;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
