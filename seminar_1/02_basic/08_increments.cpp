#include <iostream>

int main() {
    int x = 5, y = 5, a, b;
    
    a = x++;
    b = ++y;

    // может быть опасно
    // x = x++;
    // y = ++y;
    
    // что будет выведено на экран?
    std::cout << "a = x++ => a = " << a << std::endl;
    std::cout << "b = ++x => b = " << b << std::endl;
}
