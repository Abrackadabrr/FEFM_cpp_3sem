#include <vector>
#include <iostream>


// Из reverse iterator можно получить "прямой" с помощью метода base

int main() {
    std::vector cont{1, 2, 3, 4, 5, 6, 7}; 
    auto crvi = cont.crbegin();

    // 1 2 3 4 5 6 7 <

    std::cout << *crvi << std::endl;

    std::advance(crvi, 4);

    // 1 2 3 < 4 5 6 7

    std::cout << *crvi << std::endl;

    auto cvi = crvi.base();

    std::cout << *cvi << std::endl;

    // 1 2 3 > 4 5 6 7
}
