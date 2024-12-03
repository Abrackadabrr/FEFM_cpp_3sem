#include <iostream>

void swap_arrays(int *t1 [3], int *t2 [3]) {
	int tmp[3] = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

void print(int n, int a[]) {
	std::cout << a[n/2];
}
	

int main() {
	int a[3] = {0, 1, 2};
	int b[3] = {3, 4, 5};
	print(a);
	swap_arrays(&a, &b);
	std::cout << a[0];
}
