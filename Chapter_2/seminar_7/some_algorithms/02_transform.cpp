#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// for_each немодифицирующий
// но мы можем сделать его таким

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto check = [](int a) -> int { return a == 7; };
    auto action = [](int a) {std::cout << a << std::endl;};

    std::for_each(v.begin(), v.end(), [](int& a) { a = -a; });
//    std::transform(v.begin(), v.end(), v.begin(), [](int& a) { return -a; });
    std::for_each(v.begin(), v.end(), action);
}
    // Мы хотим трансформировать последовательность
    // Для этого у на есть отдельный алгоритм