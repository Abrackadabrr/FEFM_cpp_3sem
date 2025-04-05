#include <iostream>
#include <map>

template<typename Cnt>
void print_map(const Cnt& m)
{
    for (const auto& n : m)
        std::cout << n.first << " = " << n.second << "; ";
    std::cout << '\n';
}
 

int main() {
    std::map<int, int> m{{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    print_map(m);
    // Хотим удалить элемент по значению
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == 1)
            m.erase(it);
    }
    print_map(m);
}
