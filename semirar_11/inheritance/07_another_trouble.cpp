struct Base1 {
    int a;    
};

struct Derived1 : virtual public Base1 {
    int b;
    Derived1(int a): Base1{a}, b(2 * a) {}
};

struct Derived2 : virtual public Base1 {
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

    // Base1* base_1 = derived_p;  // сработает?
    // derived_p = static_cast<Derived*>(base_1);  // сработает?
}
