#include <iostream>

int main() {
	int x[2] = {10, 20};
	int &xref = x[0];  // теперь я могу обратиться к нулевоу элементу массива через другое имя xref
	int *xptr = &x[0];  // а вот это уже указатель на первый элемент
	xref += 1;  
	xptr += 1;
	// что будет выведено на экран?
	std::cout << xref  << ' ' << x[0] << ' ' << *xptr << std::endl;
}
