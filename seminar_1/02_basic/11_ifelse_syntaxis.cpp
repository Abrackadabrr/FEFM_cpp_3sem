#include <iostream>

int main() {
    bool flag;
    std::cin >> flag;
    if (flag) {
        std::cout << "Flag is true" << std::endl;
    } else {
        std::cout << ( (flag) ? "Flag is true" : "Flag is false" ) << std::endl;
    }

    int i;
    std::cin >> i;
    if (i < 5)
        std::cout << "Less than 5";
    else if (i > 5 && i < 10)
         std::cout << "Greater of equal than 5, but less than 10";
    else if
    else std::cout << "Greater of equal than 10";
    
    std::cout << std::endl;    
    return 0;
}
