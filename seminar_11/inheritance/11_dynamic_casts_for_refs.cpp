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
    Derived derived{1};
    Derived& derived_ref = derived;
 
    Base1& base_1 = derived_ref;  // сработает!
    
    derived_ref = dynamic_cast<Derived&>(base_1);  // тоже сработает?
    
    Derived1& derived_1_ref = dynamic_cast<Derived1&>(base_1); // сработает?

    Derived2& derived_2_ref = dynamic_cast<Derived2&>(derived_1_ref); // сработает?

    // а если вот так кастануть?
    Derived1 derived_1{5};
    Derived1& ref = derived_1;
    derived_2_ref = dynamic_cast<Derived2&>(ref);  // сработает?

    std::cout << derived_2_ref.a << std::endl;
}

// dynamic_cast работает и для ссылок
// при невозможности каста, он бросает exception
