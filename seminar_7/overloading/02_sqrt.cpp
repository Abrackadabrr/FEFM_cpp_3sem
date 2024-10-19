// Язык С++ позволяет определять функции с одним и тем же именем, 
// но разным набором параметров. 
// Подобная возможность называется перегрузкой функций (function overloading). 
// Компилятор же на этапе компиляции на основании параметров выберет нужный тип функции.


#include <iostream>

int sum(int a, int b) {
	std::cout << "int sum" << std::endl;
	return a + b;
}


float sum(float a, float b) {
	std::cout << "float sum" << std::endl;
	return a + b;
}


double sum(double a, double b) {
	std::cout << "double sum" << std::endl;
	return a + b;
}


int main() {
	int a = 5, b = 5;
	sum(a, b);
	sum(1., 3.);
	sum(1.f, 3.f);
}
