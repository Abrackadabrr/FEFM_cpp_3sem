#include <iostream>

using std::cout;
using std::endl;

// у консруктора копирования есть специальная семантика -- он используется в RVO (Return Value Optimization)

struct foo {
  foo() { cout << "Ctor" << endl; }
  foo(const foo &) { cout << "Copy Ctor" << endl; }
  ~foo() { cout << "Dtor" << endl; }
};

foo bar() {
  foo local_foo;
  return local_foo;
}

int main() { foo f = bar(); }

// объект до копирования эквивалентен объекту после
// 
// компилятор протянул, что bar()::local_foo эквивалентен main::f по опеределению копирования
// это сделано даже выше чем уровень оптимизации, на уровне фрондтенда языка.

