#include <iostream>

struct myInt {
	int a;
	// конструктор по умолчанию 
	// default init
	myInt() {
		a = 0;
		std::cout << "default" << std::endl;
	}
	// перегружаем констуктор здесь
	// direct init
	myInt(int value) {
		a = value; 
		std::cout << "direct" << std::endl;
	}
};

struct Node {
	myInt value_;
	Node * next_;

	Node(int a) {
		value_ = a;  // copy init 
	}
};

int main() {
	Node node{3};
}

// что будет на экране?
// hint: внутри конструктора поле value УЖЕ должно быть проинициализировано
