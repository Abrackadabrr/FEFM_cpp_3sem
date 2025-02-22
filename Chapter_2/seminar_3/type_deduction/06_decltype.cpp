// decltype позволяет узнать тип имени, с которым оно было введено

#include "deduce_type.hpp"

int main() {
    const int &a = 10;
    auto b = a;
    decltype(a) c = a;

    deduce_type d1(b);
    deduce_type d2(c);

}

// Таким образом, dectype(a) == const int &
