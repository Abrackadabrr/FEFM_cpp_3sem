#include <iostream>
#include <climits>

int main ()
{
    int x;

    std::cin >> x;

    for (int i = sizeof(int) * CHAR_BIT - 1; i >= 0; i--) {
        // битовая маска 0000000000000001
        const int mask = 1;
        std::cout << ((x >> i) & mask);
    }

    std::cout << " " << std::endl;

    return 0;
}
