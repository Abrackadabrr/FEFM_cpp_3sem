// dynamic_cast может всё

#include <iostream>
#include <cassert>
#include <string>

struct Base1 {
    int a;
    Base1(int a_): a(a_) {}; 
    //virtual std::string name() {return " ";}
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
    Derived* derived_p = new Derived{1};

    Base1* base_1 = derived_p;  // сработает!
    // derived_p = dynamic_cast<Derived*>(base_1);  // тоже сработает?
}
