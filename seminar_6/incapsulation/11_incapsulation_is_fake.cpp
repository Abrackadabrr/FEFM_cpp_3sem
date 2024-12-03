#include <iostream>

struct T {
private:
	int a;
	int b;
	int c;
public:
	T() {
		// будем считать значения этих переменных инвариантами класса
		a = 3;
		b = 4;
		c = 5;	
	}

	int getA() const {return a;}
};

int main() {
	// создал объект
	T a{};
	int *public_pointer = (int *)(&a);
	public_pointer[0] = 10;
	std::cout << a.getA() << std::endl;
}


// private -- это невозможность использовать имя, а не модификатор данных (как const, например)
//
// обсуждение: ссылки есть в некотором роде инкапсуляция указателей

