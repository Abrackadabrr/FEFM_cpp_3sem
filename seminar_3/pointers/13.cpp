#include <iostream> 

void f() {
    int a, b;
    a = 5; b = 6;
    std::cout << std::dec << (long)(&a) << ' ' << (long)(&b) << std::endl;
}

void g() {
    int mas[101];
    std::cout << (long)(&mas[100]) << ' ' << (long)(&mas[98]) << std::endl;
    std::cout << (mas[100]) << std::endl;
}

int main() {
    int a, b;
    f();
    g();
    return 0;
}
