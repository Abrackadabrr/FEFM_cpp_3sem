#include <iostream>

int foo(int a) {
	return a + 1;
}

using f_p_t = int(*)(int);

int main() {
	std::cout << "Размер указателя на функцию: " << sizeof(f_p_t) << std::endl;

	f_p_t pointer = foo;
	// арифметика с такими указателями запрещена.
	// аримфетика разрешена только с указателями на объекты, а указатель на функцию не является указателем на объект.
	return 0;
}
