#include <iostream>

int main() {
    int x = 5, y = 5;
    x = x++;
    y = ++y;
    // что будет выведено на экран?
    std::cout << x << " " << y << std::endl;
}
