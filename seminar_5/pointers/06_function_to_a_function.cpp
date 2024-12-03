#include <iostream>

using f_p_t = int (*) (int);

int mul(int a) {
	return 10 * a;
}

int incr(int a) {
	return a + 1;
}

void array_transform(int * a, int n, f_p_t incr) {
	for (int i = 0; i < n; i++)
		a[i] = incr(a[i]);
}

int main() {
	int a[3] = {0, 1, 2};
	array_transform(a, 3, incr);
	array_transform(a, 3, mul);
	std::cout << a[1] << std::endl;
	return 0;
}
