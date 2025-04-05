#include <iostream>
#include <unordered_map>

int main () {
    std::unordered_map<int, int> m;
    m.reserve(10);
    m.max_load_factor(2);
    for (int i = 0; i < 40; ++i)
        m.insert(std::make_pair(i, i));

    std::cout << m.bucket_count() << std::endl;
    std::cout << m.load_factor() << std::endl;

    for (int i = 0; i < m.bucket_count(); ++i) {
        std::cout << "Bucket #" << i << std::endl;
        for (auto it = m.begin(i); it != m.end(i); ++it)
            std::cout << it->first << " ";
            std::cout << std::endl;
    }

// Rehash позволяет пересчитать хэши в таблице
// и увеличить размер
    m.rehash(100);
    std::cout << m.bucket_count() << std::endl;
    std::cout << m.load_factor() << std::endl;

    for (int i = 0; i < m.bucket_count(); ++i) {
        std::cout << "Bucket #" << i << std::endl;
        for (auto it = m.begin(i); it != m.end(i); ++it)
            std::cout << it->first << " ";
            std::cout << std::endl;
    }

}
