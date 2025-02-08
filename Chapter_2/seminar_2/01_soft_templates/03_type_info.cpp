#include <iostream>

template<typename v_type>
void templated_sizeof(v_type var = v_type{} /* var не используется в теле функции*/) {
    std::cout << sizeof(v_type) << std::endl;
}

struct MyStructure{
    int a;
    char b;
    char c;
    double d;
};


int main() {

    templated_sizeof<int>();
    templated_sizeof<short>();
    templated_sizeof<long>();
    templated_sizeof<double>();
    templated_sizeof<float>();
    templated_sizeof<char>();
    templated_sizeof<MyStructure>();
}

// Написали один раз -- пользуемся сколько угодно раз
// Вызов теперь выглядит будто мы просто аргументы пишем
// внутри < >.
