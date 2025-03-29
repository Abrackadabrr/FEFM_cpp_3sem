#include <string>
#include <vector>

#include <iostream>

int main() {
    std::string s{"Hello, World!"};
    // string -- это alias
    // string -- это "вектор с дополнительным интерфейсом"
    std::cout << s << std::endl;
    std::cout << s.length() << std::endl;
    std::cout << s.erase(10, 1) << std::endl;
    s += " I am virus";
    std::cout << s << std::endl;

    // Поиск подстроки в строке

    // Подстрока не найдена
    auto where = s.find("worm");
    std::cout << std::boolalpha << (where == std::string::npos) << std::endl;

    // Подстрока найдена
    where = s.find("Hell");
    std::cout << where << std::endl;
}
