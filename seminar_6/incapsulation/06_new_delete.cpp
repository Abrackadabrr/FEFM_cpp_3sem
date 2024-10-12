#include <iostream>

struct stack {
	int size;
	int *a;
	int top;

	// в методах типа init и finzlize
	// в с++ прудусмотрены конструкторы и деструкторы
	//
	// конструктор -- это обычный метод, который вызывается при создании объекта
	// называется так же как и класс и не имеет возвращаемого типа
	stack(int size_st = 1000) {
		size = size_st;
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
	stack *stack_array = new stack[10];
	// ... some job ... // 
	delete[] stack_array;
	return 0;	
}
