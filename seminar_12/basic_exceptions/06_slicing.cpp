#include <iostream>

struct A {
  int a_;
  A(int a) : a_(a) {}
  A(const A & rhs): a_(rhs.a_) {std::cout << "A copyCtor" << std::endl;}
  virtual void dump(std::ostream &os) const { os << a_; }
  virtual ~A() {}
};

struct B : public A {
  int b_;
  B(int b) : A(b / 2), b_(b) {}
  B(const B & rhs): A(rhs.a_), b_(rhs.b_) {std::cout << "B copyCtor" << std::endl;}
  void dump(std::ostream &os) const override { os << a_ << " " << b_; }
};

std::ostream &operator<<(std::ostream &os, const A &a) {
  a.dump(os);
  return os;
}

void foo(A a) { std::cout << a << std::endl; }

void bar(A &a) { std::cout << a << std::endl; }

int main() {
  B b1(10);
  foo(b1);
  bar(b1);
}

// В foo происходит срезка, потому что аргумент
// принимается по значению, и вызывается консруктор копирования
// для базового класса, что логично

// bar таких проблем лишена, потому что ничего не копируется

// Случай с исключениями как раз про то, что при ловле
// по значению мы фактически передаем аргумент в 
//  catch блок по значению, и он срезается