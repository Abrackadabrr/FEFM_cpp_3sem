#include <map>
#include <string>
#include <iostream>
#include <algorithm>

// std::map -- это дерево, 
// хранящая пары {ключ, значение}
// и при этом упорядоченное 
// по ключам 

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment << std::endl;
    for (const auto& n : m)
        std::cout << n.first << " = " << n.second << "; ";
    std::cout << '\n';
}
 
int main()
{
    // Создаем мапу
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
 
    print_map("1) Initial map: ", m);
 
    m["CPU"] = 25; // Изменяем значение
    m["SSD"] = 30; // Добавляем значение
    print_map("2) Updated map: ", m);
 
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) Updated map: ", m);
 
    m.erase("GPU");
    print_map("5) After erase: ", m);
 
    std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
    print_map("6) After erase: ", m);
    std::cout << "7) m.size() = " << m.size() << '\n';
 
    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}
