#include <iostream>
#include "demangle.hpp"


// Периодически есть куски кода, когда мы можем
// не дублировать тип переменной

template<typename T>
struct deduce_type {
    deduce_type(T& value) {
        std::cout << demangle(typeid(*this).name()) << std::endl;
    }
};

int main() {
    int *a_ptr = new int[10];  // написали int два раза, хотя понятно, что в объявлении нужен int
    
    // Давайте заствим комплятор выводить 
    // тип переменной самостоятельно
    
    auto b_ptr = new int[10];
    deduce_type d1(b_ptr);

    const int * c_ptr = new int[10];  // (добавить сюда const)
    deduce_type d2(c_ptr);

    auto d_ptr = c_ptr;
    deduce_type d3(d_ptr);

    auto *e_prt = c_ptr;
    deduce_type d4(e_prt);

    auto c1 = c_ptr[1];
    deduce_type d5(c1);

    auto &c2 = c_ptr[1];
    deduce_type d6(c2);
}

// Компилятор сам догадался, что тип b_ptr -- это int *
// ПРАВИЛО: auto выводит тип точно так же, как это делают шаблоны
// Таким образом, неуточненное auto будет отрезать const и &

// Отлично, auto режет нам типы. А вот то что мы написали (deduce_type)
// типы не режет и правильно их печатает. Есть ли уже такое в тсандарте?