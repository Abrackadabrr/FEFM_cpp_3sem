// Что нужно написать, чтобы указатель был "нулевой"?
//
// NULL -- зарезервированное "нулевое значение" указателя
// разыменование NULL pointer'а приведет к уже известной ошибке сегментации

#include <iostream>

int main() {
	int * i_p;
	std::cout << std::boolalpha << (i_p == NULL) << std::endl;
	std::cout << std::hex << (long)(i_p) << std::endl;
	std::cout << std::hex << (long)(NULL) << std::endl;
	i_p = NULL;
	*(i_p) = 0;  // segmentation fault
	// нулевой указатель приводится к типу bool со значением false
	if (i_p) {
		std::cout << "Never printable" << std::endl;
	} else {
		std::cout << "Yes, it's false" << std::endl;
	}
	
	return 0;
}
