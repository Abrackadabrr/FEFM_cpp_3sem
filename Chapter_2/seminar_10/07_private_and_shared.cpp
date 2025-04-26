#include <iostream>
#include <array>
#include <iterator>

// Все ли хорошо в данном коде?
// Не будет ли тут проблем с памятью?

int main() {
    std::array<int, 10> array;

#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        array[i] += 10;
    }
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
}









// Проблем не будет, потому что
// i -- это private переменная
// array -- это shared переменная, 
//          но пишем мы в разную (!) память