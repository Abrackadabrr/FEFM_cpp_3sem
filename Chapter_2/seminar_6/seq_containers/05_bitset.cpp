#include <bitset>
#include <array>
#include <iostream>

// В чем проблема std::array<bool>?

int main() {
    std::bitset<32> s1 = 0xf0ffffff;
    std::bitset<32> s2 = 0xaaaaaaaa;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s1.to_ulong() << std::endl;
    std::cout << (s1 & s2) << std::endl;
    std::cout << (s1 | s2) << std::endl;
}
