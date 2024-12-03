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
    Derived* derived_p = new Derived{1};

//    Base1* base_1 = derived_p;  // сработает!
//    std::cout << "&Base1 = " << std::hex << base_1 << std::endl;


//     derived_p = dynamic_cast<Derived*>(base_1);  // тоже сработает?
//     std::cout << "&Derived = " << std::hex << derived_p << std::endl;
    
//     Derived1* derived_1_p = dynamic_cast<Derived1*>(base_1); // сработает?
//     std::cout << "&Derived1 = " << std::hex << derived_1_p << std::endl;
//     Derived2* derived_2_p = dynamic_cast<Derived2*>(derived_1_p); // сработает?
//     std::cout << "&Derived2 = " << std::hex << derived_2_p << std::endl;

//     // а если вот так кастануть?
//     Derived1* derived_1_p1 = new Derived1{0};
//     derived_2_p = dynamic_cast<Derived2*>(derived_1_p1);  // срабоnает?
//     std::cout << "Strange adress = " << std::hex << derived_2_p << std::endl;
}

// dynamic_cast может ходить по иерархии классов 
// как угодно, лишь бы классы существовали

// есть надежда на то, что компилятор 
// использует вместо dynamic_cast static_cast и все будет сильно проще
// это прописано в стандарте

// Но никто не гарантирует, что это случится!
