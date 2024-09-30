// константный указатель и указатель на константные данные -- это разные вещи
//

#include <iostream>

void passing_by_const_pointer(int * (const a)) {
//	a = a+1 // compilation error
	a[3] = 0;
	return;
}	

void passing_by_pointer_to_const(const int * a) {
//	a[3] = 0; // compilation error
	a = a + 1;
	return;
}

int main() {
	int a[4] = {0, 1, 2, 3};
	int *a_p = new int[4];
	passing_by_const_pointer(a);
	passing_by_pointer_to_const(a_p);
	return 0;
}
