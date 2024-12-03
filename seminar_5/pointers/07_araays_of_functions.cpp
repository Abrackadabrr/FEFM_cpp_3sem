#include <iostream>

int incr(int a) {
	return a + 1;	
}

int mul(int a) {
	return 18 * a;
}

int sub2(int a) {
	return a - 2;
}

// массив из указателей на функцию
using array_of_functions = int (*[3]) (int);

int main() {
	array_of_functions operations = {incr, mul, sub2};

	int a = 3;

	for (int i = 0; i < 3; i++) 
		a = operations[i](a);
	std::cout << a[1] << std::endl;
}
