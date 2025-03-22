#include <iostream>
#include "list.hpp"

// В языке есть удобный синтаксис
// который называется range based for

template<typename Cont, typename Predicate>
bool check_smart(const Cont& v, const Predicate& pred) {
    for (auto element: v) {
        if (pred(element))
            return true;
    }
    return false;
}

/*

auto __begin = begin(v);
auto __end = end(v);

for (; __begin != end; ++__begin) {
    element = *__begin;

    ---- loop statement ---
}

*/

int main() {
    f_list<int> l{};
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    std::cout << std::boolalpha << check_smart(l, [](int a)->bool{ return a == 3;}) << std::endl;
}
