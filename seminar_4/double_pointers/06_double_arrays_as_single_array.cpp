#include <iostream>

// двумерный массив можно представить как одномерный, но тогда нужно каждый раз производить пересчет индекса

using namespace std;
int main () {
	int *m = new int[5 * 5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			m[i * 5 + j] = i * 5 + j; //m[i][j] <- нельзя
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << m[i * 5 + j] << ' ';
		cout << endl;
	}

	delete[] m;
	return 0;
}
