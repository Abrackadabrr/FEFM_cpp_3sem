#include <iostream>

// В стандартной бибилиотеке 
// конечно же все уже написали за вас

template<bool v>
using get_type = std::conditional_t<v, int, double>;

int main() {
    std::cout << sizeof(get_type<true>) << std::endl;
    std::cout << sizeof(get_type<false>) << std::endl;
}
