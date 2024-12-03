#include <iostream>
struct stack {
	int size;
	int *a;
	int top;

	// в методах типа init и finalize
	// в с++ прудусмотрены конструкторы и деструкторы
	//
	// конструктор -- это обычный метод, который вызывается при создании объекта
	// называется так же как и класс и не имеет возвращаемого типа
	stack(int stack_size) {
		size = stack_size;
		a = new int[size];
		top = 0;
		std::cout << "Ctor" << std::endl;
	}

	// деструктор -- это метод, который вызывается при окончании времени жизни объекта
	~stack() {
		delete[] a;
		std::cout << "Dtor" << std::endl;
	}
};

int main() {
	stack s{100};
	s.top = 4;
	std::cout << "hey" << std::endl;
}
