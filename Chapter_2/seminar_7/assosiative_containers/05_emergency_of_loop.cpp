#include <iostream>
#include <unordered_map>

int main () {
    std::unordered_map<int, int> m;
    m.reserve(10);
    m.max_load_factor(2);
    for (int i = 0; i < 40; ++i)
        m.insert(std::make_pair(i, i));

// Подряд поэлементно до рэхеша
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << " ";
    std::cout << std::endl;

    m.rehash(80);

// Подряд поэлементно после рэхеша
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << " ";
    std::cout << std::endl;

// Изменился ли порядок обхода?
}
