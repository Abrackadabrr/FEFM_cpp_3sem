// ещё одна проблема -- преобразования

#include <iostream>

struct Base1 {
    int a;    
};

struct Base2 {
    int b;
};

struct Base3 {
    int c;
};

struct Derived : public Base1, public Base2, public Base3 {
    int d;
    Derived(int a): Base1{a}, Base2{2 * a}, Base3{3 * a}, d(a) {}
};

int main() {
    Derived* derived_p = new Derived{1};

    std::cout << "Down casts" << std::endl;

    std::cout << std::hex << "derived adress = " << derived_p << std::endl;

    // пытаемся кастануть указатели, 
    // как при обычном одиночном наследовании
    Base1* base_1_p = static_cast<Base1*>(derived_p);
    Base2* base_2_p = static_cast<Base2*>(derived_p);
    Base3* base_3_p = static_cast<Base3*>(derived_p);
#if 0
    std::cout << std::hex << "base 1 adress = " << base_1_p << std::endl;
    std::cout << std::hex << "base 2 adress = " << base_2_p << std::endl;
    std::cout << std::hex << "base 3 adress = " << base_3_p << std::endl;

    std::cout << std::hex << "specific adress = " 
            << &(base_3_p->c) + 1 << std::endl;
    std::cout << (*(&(base_3_p->c) + 1)) << std::endl;
#endif
    std::cout << "Up casts" << std::endl;

    std::cout << "derived casted adress = " 
    << static_cast<Derived*>(base_1_p) << std::endl;
    std::cout << "derived casted adress = " 
    << static_cast<Derived*>(base_2_p) << std::endl;
    std::cout << "derived casted adress = " 
    << static_cast<Derived*>(base_3_p) << std::endl;
}



// static_cast меняет битовое представление 
// переменной, это неудивительно

// static_cast знает на этапе компиляции 
// сколько и откуда вычитать, чтобы преобразовать адреса
