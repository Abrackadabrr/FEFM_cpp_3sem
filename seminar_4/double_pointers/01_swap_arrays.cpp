#include <iostream>

void swap_arrays(int *a, int *b, int n) {
        // a -> tmp (for)
        // b -> a
      	// tmp -> b
}


int main() {
	int *a = new int[3]; a[0] = 0; a[1] = 1; a[2] = 2;
        int *b = new int[3]; b[0] = 3; b[1] = 4; b[2] = 5;

        swap_arrays(/*???*/);

        print_array(3, a);
        print_array(3, b);


	delete[] a;
	delete[] a;
}
