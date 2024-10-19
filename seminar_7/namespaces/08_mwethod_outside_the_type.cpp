#include <iostream>

struct myClass {
	int a_;
	myClass(int a);
	int getA();
	~myClass();
}

myClass::myClass(int a) {
	a_ = a;
}

myClass::~myClass() {};

int myClass::getA() {
	return a;
}

// классы и структуры тоже опеределяют свое просранство имен
// так что теперь синтаксис определения функции вне класса не есть запоминалка с магией
