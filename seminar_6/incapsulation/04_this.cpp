#include <iostream>

struct Int {
	int a;

	Int * getThis() {
		return this;	
	}
};

int main() {
	Int a{4};
	std::cout << a.getThis() << std::endl;
	std::cout << &a << std::endl;
}

