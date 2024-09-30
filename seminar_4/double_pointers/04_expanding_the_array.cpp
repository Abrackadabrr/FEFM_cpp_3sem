#include <iostream>

void expand(int **a, int old_size, int new_size) {
	int* new_a = new int[new_size];
	for (int i = 0; i < old_size; i++) {
		new_a[i] = *((*a)+i);
	}
	delete[] *a;
	*a = new_a;
}

int main() {
	int *a = new int[100]

	// мы этот массив поиспользовали, и поняли, что нам не хватает памяти, стандартный сюжет. Нужно памяти добавить
	
	expand(a, 100, 1000);
	// и давай дальше использовать этот большой массив
	

	delete[] a;
	return 0;
}
