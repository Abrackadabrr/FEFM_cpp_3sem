#include <iostream>

// Шаблонить можно не только типами, 
// но и экземплярами типов данных

// Шаблон по типу (ключевое слово typename)
template<typename T>
T foo(T x) {return 0;};

template<int N>
int foo(int x) { return N; };

int main() {
    std::cout << foo<int>(1) << std::endl;
    std::cout << foo<1>(1) << std::endl;
    // здесь НЕ БУДЕТ коллизии имен функции foo
}
