#include <iostream>
#include <cassert>
#include <string>

struct Base1 {
    int a;
    Base1(int a_): a(a_) {}; 
    virtual ~Base1() {}
};

struct Derived1 : virtual Base1 {
    int b;
    Derived1(int a): Base1{a}, b(2 * a) {}
};

struct Derived2 : virtual Base1 {
    int c;
    int e;
    Derived2(int a): Base1{a}, c(3 * a), e(4 * a) {}
};

struct Derived : public Derived1, public Derived2 {
    int d;
    Derived(int a): Base1{a}, Derived1{2 * a}, Derived2{3 * a}, d(a) {}
};


int main() {
    Base1* base_p = new Derived{0};
    if(typeid(*base_p) != typeid(Derived)){
        std::cout << "Failed" << std::endl;
        
    } else {
        std::cout << "Success" << std::endl;
    }
    std::cout << typeid(*base_p).name() << std::endl;

    std::cout << typeid(base_p).name() << std::endl;
}

// typeid берет тип или lvalue-выражение и 
// выводит динамический тип только 
// если у объекта есть хотя бы одна 
//виртуальная функция, 
// иначе будет отпределён статический тип


