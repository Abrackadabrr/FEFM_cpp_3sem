#include <iostream>

bool foo() {
    std::cout << "foo" << std::endl;
    return false; 
}

bool bar() {
    std::cout << "bar" << std::endl;
    return true; 
}

int main() {
    if (foo() && bar()) {
        std::cout << "foo() && bar() == true" << std::endl;
    }

    if (bar() || foo()) {
        std::cout << "bar() || foo() == true" << std::endl;
    }
}

// если оператор && перегружен, то он теряет такое свойство