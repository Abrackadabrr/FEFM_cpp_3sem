#include <iostream>

// void pointer is a pointer to a typeless memory (raw bytes)

int main() {
	int n = -10;
	void *pointer = &n;
//	std::cout << *pointer << std::endl;
	std::cout << *((int*)pointer) << std::endl;
	std::cout << *((unsigned*)pointer) << std::endl;
	std::cout << *((unsigned short*)pointer) << std::endl;
	std::cout << (int)*((unsigned char*)pointer) << std::endl;
}
