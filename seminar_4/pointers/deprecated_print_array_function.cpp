#include <iostream>

void print_array_v1(int * a) {
        for (int i = 0; i < 5; i++)
                std::cout << a[i] << ' ';      
	std::cout << std::endl;
} 

void print_array_v2(int a[5]) {
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << ' ';	
	std::cout << std::endl;
}

int main() {
	int a[5] = {0, 1, 2, 3, 4};
	int *a_p = new int[5];
	int b[5];
	b = (int [5])(a_p);
	
	print_array_v1(a);
	print_array_v1(a_p);
	print_array_v2(a);
	print_array_v2(a_p); // compilation error
	return 0;
}
