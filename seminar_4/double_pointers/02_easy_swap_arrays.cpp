#include <iostream>

void print_array(int n, int * a) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

void swap_arrays(int n, int **p_array_0, int **p_array_1) {
	int* tmp = *p_array_0;
	*p_array_0 = *p_array_1;
	*p_array_1 = tmp;
}

int main() {
	int *a = new int[3]; a[0] = 0; a[1] = 1; a[2] = 2;
	int *b = new int[3]; b[0] = 3; b[1] = 4; b[2] = 5;
	
	swap_arrays(3, &a, &b);

	print_array(3, a);
	print_array(3, b);
}
