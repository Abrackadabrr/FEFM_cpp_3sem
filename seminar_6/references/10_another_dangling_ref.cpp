#include <iostream>


int& refret() {
	int a[1000];
	a[99] = 10;

	//...  some job ...
	return a[99];
}

int main() {
	int &a = refret();
	std::cout << a << std::endl;
}

// const решает?
