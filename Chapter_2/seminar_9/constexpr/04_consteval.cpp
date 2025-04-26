#include <iostream>

// Для того, чтобы зафорсить вызов на этапе
// компиляции можно аннотировать её как 
// consteval (since C++20)

consteval int square(int x) {
    return x *x ;
}

int main() {
    constexpr int array[square(5)] = {1, 2, 3, 4, 5};
    std::cout << square(array[0]) << std::endl;
}
