#include <iostream>
#include <vector>
#include <algorithm>

// Самый простой немодифицируюющий алгоритм
// это алгоритм for_each

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto check = [](int a) { return a == 7; };
    auto action = [](int a) {std::cout << a << std::endl;};

    std::for_each(v.begin(), v.end(), action);
}
