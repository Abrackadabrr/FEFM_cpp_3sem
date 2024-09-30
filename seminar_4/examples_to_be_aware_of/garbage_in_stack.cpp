#include <iostream>

void f() {
    int a[100], b[100];
    for (int i = 0; i < 100; i++) {
    	a[i] = i;
	b[i] = i;
    }
    return;
}

void g() {
    int mas[100];
    std::cout << mas[23] << ' ' << mas[45] << std::endl;
}

int main() {
    int a, b;
    // функция f сделала на стеке свои дела и перестала им пользоваться
    f();
    // эту же память отдали функции g
    g();
    return 0;
}

