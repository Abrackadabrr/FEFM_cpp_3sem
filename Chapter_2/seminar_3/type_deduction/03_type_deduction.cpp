
#include <iostream>
#include "demangle.hpp"


template<typename T>
void deduce_type(T /*value*/) {
    std::cout << demangle(typeid(T).name()) << std::endl;
}

int main() {

    deduce_type(5);
    deduce_type(5.);
    deduce_type(5.f);

    int a = 5;
    deduce_type(a);

    const int ca = 4;
    deduce_type(ca);

    int & a_r = a;
    deduce_type(a_r);

    const int & ca_r = ca;
    deduce_type(ca_r);

    int && a_rr = 5;
    deduce_type(a_rr);

    int * a_ptr = &a;
    deduce_type(a_ptr);
}


// Получается, что компилятор отрубает const и &/&&
