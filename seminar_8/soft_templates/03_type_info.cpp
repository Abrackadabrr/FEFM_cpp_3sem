#include <iostream>

template<typename v_type>
void templated_sizeof(v_type var /* var не используется в теле функции*/) {
    std::cout << sizeof(v_type) << std::endl;
}

struct MyStructure{
    int a;
    char b;
    char c;
    double d;
};


int main() {

    templated_sizeof<int>(5);
    templated_sizeof<short>(5);
    templated_sizeof<long>(5);
    templated_sizeof<double>(5);
    templated_sizeof<float>(5);
    templated_sizeof<char>(5);
    templated_sizeof<MyStructure>(MyStructure{1, 1, 1, 1});
}

// Написали один раз -- пользуемся сколько угодно раз