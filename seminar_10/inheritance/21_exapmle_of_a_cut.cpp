#include <ostream>
#include <iostream>

struct A {
    int a = 0;

    virtual void dump(std::ostream &out) const {
        std::cout << a << std::endl;
    }
};

struct B : public A {
    int b = 1;

    void dump(std::ostream &out) const override {
        std::cout << a << ' ' << b << std::endl;
    }
};

void print_ref(A& a) {
    a.dump(std::cout);
}

void print_value(A a) {
    a.dump(std::cout);
}

int main() {
    B b{};
    print_value(b);
    print_ref(b);
}