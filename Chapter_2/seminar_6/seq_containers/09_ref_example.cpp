#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

template<typename Container, 
    typename T = std::void_t<decltype(std::declval<Container>().begin())>>
std::ostream& operator<<(std::ostream& os, const Container& list) {
    for (auto&& el: list)
        os << el << " ";
    return os;
};

int main()
{
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
 
    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
 
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
 
    std::cout << "list: " << l << std::endl;
    std::cout << "list, as seen through a shuffled vector: " << v << std::endl;
 
    std::cout << "Doubling the values in the initial list...\n";
    std::for_each(l.begin(), l.end(), [](int& i) { i *= 2; });
 
    std::cout << "list, as seen through a shuffled vector: " << v << std::endl;
    std::cout << "list: " << l << std::endl;
}

// Вопрос на засыпку: должна ли std::reference_wrapper 
// иметь нетривиальный деструктор? Она ведь хранит указатель.
