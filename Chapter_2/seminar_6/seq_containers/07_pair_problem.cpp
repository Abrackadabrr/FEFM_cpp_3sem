#include <iostream>
#include "list.hpp"

using list = f_list<int>;

int main() {
    std::pair<int, float> p1{10, 3.4};
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;
    // Как сделана структура?

    // Проблемы std::pair
    list l{};
    for (int i = 0; i < 10; i++)
        l.push_back(i);
    std::pair<list, list> p2{l, l};
    p2.first.print(std::cout);
}
