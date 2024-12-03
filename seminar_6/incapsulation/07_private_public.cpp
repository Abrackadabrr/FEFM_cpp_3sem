struct stack {
private:
	int size;
	int *a;
	int top;

public:
	// в методах типа init и finzlize
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
	stack() {
		delete[] a;
		std::cout << "Dtor" << std::endl;
	}
}
