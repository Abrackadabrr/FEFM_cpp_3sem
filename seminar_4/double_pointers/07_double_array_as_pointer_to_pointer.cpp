#include <iostream>

using namespace std;

int main () {
	int n = 10;
	int **m = new int*[n];
	for (int i = 0; i < n; i++)
		m[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			*(*(m + i) + j) = i * n + j; // m[i][j] = i * n + j

	*(m[2] + 3) = 0;  // ???

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << m[i][j] << ' ';

	for (int i = 0; i < n; i++)
		delete[] m[i];
	
	delete[] m;
	return 0;
}
