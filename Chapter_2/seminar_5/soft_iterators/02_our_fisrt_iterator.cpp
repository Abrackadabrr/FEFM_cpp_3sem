// Давайте попробуем изобрести какие-нибудь объекты, 
// который похожи на указатели, и позволяют нам ходить по листу

#include <iostream>

#include "list.hpp"

int main() {
    f_list<int> l{};
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    std::cout << l << std::endl;

    // Как снаружи пройтись по элементам?
    
}
