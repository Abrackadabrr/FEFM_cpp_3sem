#include <iostream>
#include <typeinfo>

int main() {
	std::cout << "Type of a constant is " << typeid(2.5f).name() << std::endl;
}
