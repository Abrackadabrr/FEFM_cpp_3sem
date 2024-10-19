#include <iostream>

using std::cout; 
using std::endl; 
// вводит имя в текущее пространство име
// в данном случае вводим std::cout std::endl в глобальное пронстраноство имен

int main() {
	cout << "Hello, World!" << endl;
}

// уже приятнее, но все равно могут возникать проблемы с конфликтом имен
