// а теперь смотрим на то, что нам в реальности сгенерировал компилятор

class Empty {
	public:
	Empty() { /* default implementation */ }

	// copy constructor
	Empty(const Empty &rhs) { /* default implementation */ } 
	
	~Empty() { /* default implementation */ }
	
	// assingment operator
	Empty& operator=(const Empty &rhs) { /* default implementation */ }
	 // .... and maybe something else ....
};

int main() {
	// вызов конструктора
	Empty a{};
	// вызов конструктора копирования
	Empty b(a);
	// вызов оператора присваивания
	b = a;
} // где-то здесь вызов деструктора

// после выхода из main время жизни класса закончится. что будет?
