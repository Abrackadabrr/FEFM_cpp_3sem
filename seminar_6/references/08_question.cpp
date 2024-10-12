#include <iostream>

int main() {
	int x = 0;
	int &xref = x;
	
	std::cout << (&x == &xref) << std::endl;

	const int &const_ref = 0;
	
	int *const_ref_pointer = &const_ref;
	
	std::cout << const_ref_pointer << std::endl;
	
	*const_ref_pointer = const_ref + 1;

	std::cout << *const_ref_pointer << std::endl;
}
