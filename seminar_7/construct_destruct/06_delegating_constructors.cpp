#include <iostream>

struct myInt {
	int a_ = 1;
	int b_ = 0;
	int c_ = 3;
	int d_ = 0;
	
	myInt() {};

	myInt(int a): /* a_(1), b_(0), c_(3), d_(0) */ {
		a_ = a > 0 ? a : 0;
		std::cout << "direct_1" << std::endl;
	}
	
	myInt(int a, int b): myInt(a) {
		b_ = b;
		std::cout << "direct_2" << std::endl;
	}

	myInt(int a, int b, int c): myInt(a, b) {
		c_ = c;
		std::cout << "direct_3" << std::endl;
	}

	myInt(int a, int b, int c, int d): myInt(a, b, c) {
		d_ = d;
		std::cout << "direct_4" << std::endl;
	}
};

int main() {
	myInt a{3, 2, 1, 0};
}

// такой вызов называется делегированием консруктора
// часть работы буквально "делегируется" другому контруктору
// делегированный конструктор всегда идет первым в списке инициализации
// при этом в списке инициализации он может быть один

// ещё одна опция для делегирования конструкторов --- реализовать один самый большой, и делегировать его 
// в обстальные конструкторы поменьше
