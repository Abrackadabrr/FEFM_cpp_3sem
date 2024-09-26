// google it on cppreference

#include <iostream>

int main() {
    int a = 3, b = 4;
    std::cout << "The sum of 3 and 4 is " << a + b << std::endl;
    // хождение слева направно и наоборот
    int c = a * b, d = (a + b) / b + a;
    a = b = c = d = 0;
}
