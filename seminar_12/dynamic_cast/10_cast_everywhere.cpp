// dynamic_cast может всё

#include <iostream>
#include <cassert>
#include <string>

struct Base1 {
    int a;
    Base1(int a_): a(a_) {}; 
    virtual ~Base1() {};
};

struct Derived1 : virtual Base1 {
    int b;
    Derived1(int a): Base1{a}, b(2 * a) {}
};

struct Derived2 : virtual Base1 {
    int c;
    Derived2(int a): Base1{a}, c(3 * a) {}
};

struct Derived : public Derived1, public Derived2 {
    int d;
    Derived(int a): Base1{a}, Derived1{2 * a}, Derived2{3 * a}, d(a) {}
};

int main() {
     Derived2* derived_2 = new Derived2{0};
     Derived1* derived_1 = dynamic_cast<Derived1*>(derived_2);
     std::cout << "Strange adress = " << std::hex << derived_1 << std::endl;
}
