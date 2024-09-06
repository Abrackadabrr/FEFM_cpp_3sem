#include <iostream>
#include <climits>

int main() {
    std::cout << "sizeof(int): " << sizeof(int) <<  "; Max: " <<  INT_MAX << std::endl;
    std::cout << "sizeof(unsigned int): " << sizeof(unsigned int) <<  "; Max: " <<  UINT_MAX << std::endl;
    std::cout << "sizeof(char): " << sizeof(char) <<  "; Max: " <<  CHAR_MAX << std::endl;
    std::cout << "sizeof(unsigned char): " << sizeof(unsigned char) <<  "; Max: " <<  UCHAR_MAX << std::endl;
    std::cout << "sizeof(long long): " << sizeof(long long) << "; Max: " << LLONG_MAX << std::endl;
    std::cout << "sizeof(unsigned long long): " << sizeof(unsigned long long) << "; Max: " << ULLONG_MAX << std::endl;
    return 0;
}
