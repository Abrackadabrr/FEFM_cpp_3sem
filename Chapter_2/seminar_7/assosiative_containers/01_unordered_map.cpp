#include <unordered_map>
#include <string>
#include <iostream>

/*
template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
> class unordered_map;
*/

// Хеш таблица предоставляет возможность
// сделать произвольное отображение из
// значений одного типа в значения другого

// В данном случае у нас есть отображение "строки -> числа"
using ht = std::unordered_map<std::string, int>;
// Неупорядоченное отображение (unordered map)
// хранит в себе std::pair<Key, Value>

int main() {
    ht table{};
    table.insert({"Alice", 10});
    table.insert({"Wayne", 894});
    table.insert({"Alex", 892});

    std::cout << table.load_factor() << std::endl;
    std::cout << table.size() << std::endl;

    std::cout << table.bucket_count() << std::endl;
//    std::cout << table.max_bucket_count() << std::endl;

    std::cout << table.bucket_size(2) << std::endl;

    std::cout << table.max_load_factor() << std::endl;
}
