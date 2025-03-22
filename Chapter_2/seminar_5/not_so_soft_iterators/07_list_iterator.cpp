#include <forward_list>
#include <iostream>
#include <iterator>

// Итераторы в списках не инвалидируются

int main() {
    std::forward_list l{1, 2, 3, 4, 5, 6};
    std::forward_list l_1{30, 40, 50};

    auto it = l_1.begin();
    std::advance(it, 0);

    std::cout << *it << std::endl;

    l.splice_after(l.begin(), l_1);

    std::cout << *it << std::endl;

    // std::cout << *(--it) << std::endl;
    std::advance(it, 5);
    std::cout << *it << std::endl;

    std::copy(l.begin(), l.end(), std::ostream_iterator<int>{std::cout, " "});
}
