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
		std::cout << "direct" << std::endl;
	}
};

struct Node {
	myInt value_;
	Node * next_;

	Node(int a): value_(a) {
		next_ = nullptr;
	};
	// в круглых скобочках указываем какое значение нужно передать полю, 
	// иначе оно будет defaut проинициализировано,
	// а это займет лишние машинные ресурсы, которые не хочется тратить

	// Такая шутка называется списком инициализации
	// Мы как будто инициализировали поле до тела конструктора (иначе оно просто было бы default init)
};

int main() {
	Node node{3};
}

// что будет на экране?
// hint: внутри конструктора поле value УЖЕ должно быть проинициализировано
