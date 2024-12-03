#include <iostream>

void f() {
    int a, b;
    a = 2;
    b = 3;
}

void g() {
    int mas[100];
    std::cout << mas[0] << ' ' << mas[1] << std::endl;
}

int main() {
    int a, b;
    // функция f поделала на стеке свои дела и перестала им пользоваться
    f();
    // эту же память отдали функции g
    g();
    return 0;
}
