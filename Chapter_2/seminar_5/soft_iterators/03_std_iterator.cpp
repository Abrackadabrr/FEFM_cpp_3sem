#include <iostream>

#include <list>

// Давайте напишем оператор вывода для листа
// с использованием итераторов

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    return os;
}

int main() {
    std::list<int> l{1, 2, 3, 4, 5, 6, 345, 546, 2134, 6};

    std::cout << l << std::endl;
}
