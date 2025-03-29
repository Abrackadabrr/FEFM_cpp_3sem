#include <iostream>
#include "list.hpp"
#include "print_type.hpp"
#include "print_type.cpp"

using list = f_list<int>;

int main() {
    list l{};
    for (int i = 0; i < 10; i++)
        l.push_back(i);
    std::pair p2{std::ref(l), std::ref(l)};
    std::cout << type_name<decltype(p2.first)>() << std::endl;
    p2.first.get().print(std::cout);
}

// И ничего скопировано не было
