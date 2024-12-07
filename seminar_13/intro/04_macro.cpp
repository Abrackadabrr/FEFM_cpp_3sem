#include <iostream>

#define VALUE 
#define ANOTHER_VALUE 0

int main() {
#if VALUE
	std::cout << "Hello, World!" << std::endl;
#endif // #if VALUE
	return ANOTHER_VALUE;
}
