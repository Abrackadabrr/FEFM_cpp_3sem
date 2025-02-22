// Итак, что нам известно:

// 1) auto режет ссылки и константность с типов
//    и для понимания типа использует правюю часть
//    
//    auto x = 10;  выведет int, поскольку 10 -- это int 
//                                               семантически

// 2) decltype дает нам тип, с которым имя было введено, 
//    при этом использует только это имя

// А что если мы захотим, чтобы при выводе не резались типы,
// и при этом была использована правая часть?

#include "deduce_type.hpp"

const int &get_const_ref() {
    int* a = new int{1};
    return *a;
};

int main() {
    //  это порежет нам тип
    auto a = get_const_ref();
    deduce_type d0(a);

    // используем decltype
    decltype(get_const_ref()) b = get_const_ref();
    deduce_type d1(b);
    // ну и здесь мы два раза написали название функции
    // мы хотим писать мало кода

    decltype(auto) c = get_const_ref();
    deduce_type d2(c);

    // decltype(auto) -- это единое выражение
    // оно означает, что мы выводим по правилам decltype, при этом используем правую часть

    // заметим, что такое выражение мы ещё не встречали
    // decltype(get_const_ref()) -- это не decltype(имя)
}
