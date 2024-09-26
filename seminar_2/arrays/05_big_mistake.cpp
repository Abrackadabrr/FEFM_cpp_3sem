#include <iostream>

int main() {

    int a[3] = {0, 1, 2};
    for (int i = 0; i < 3; i++) {
        a[-1] = 0;
        std::cout << a[i] << std::endl;
    }
    return 0;
}
