#include <iostream>
#include <vector>


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto check = [](int a) { return a == 7; };
    auto action = [](int a) {std::cout << a << std::endl;};

    for (auto&& el : v) 
        if (check(el)) {
            action(el);
            break;
        }
    // Что бы мы хотели тут сделать? Нам нужен один алгоритм
}
