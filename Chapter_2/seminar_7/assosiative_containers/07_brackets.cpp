#include <iostream>
#include <unordered_map>

struct MyInt {
    int v;
    MyInt(): v(-100) { std::cout << "Def" << std::endl; }
    MyInt(int a) : v(a) {}
};

std::ostream& operator<<(std::ostream& os, const MyInt& mi) {
    os << mi.v;
    return os;
};

int main () {
    std::unordered_map<int, MyInt> m;
    m.reserve(10);
    m.max_load_factor(10.0);
    for (int i = 0; i < 30; ++i)
        m.insert(std::make_pair(i, i));

    // Будем стучаться по ключу через квадратные скобки
    std::cout << m[10] << std::endl;
    // А тут что будет?
    std::cout << m[40] << std::endl;
}
