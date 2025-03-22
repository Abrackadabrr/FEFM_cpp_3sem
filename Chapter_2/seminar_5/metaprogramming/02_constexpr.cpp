#include <iostream>

template<int I>
constexpr int get_value() {
    return I;
}

int main() {
    std::cout << get_value<5>() << std::endl;
}