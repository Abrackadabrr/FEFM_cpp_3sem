#include <iostream>

int main() {
    int b = 5; int c = 7;
    int a[3] = {0, 1, 2};
    int d[3] = {10, 20, 30};
    a[-1] = 0;
    a[-2] = 0;
    a[3] = 105;
    std::cout << b << ' ' << c << ' ' << d[0] << std::endl;
    return 0;
}

