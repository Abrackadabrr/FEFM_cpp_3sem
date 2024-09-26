// а -- это имя передаваемого массива
// n -- количество элементов в массиве

#include <iostream>

int sum(int *a, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }    
    return res;
}

int main() {
    const int n = 3;
    int a[n] = {0, 1, 2};
    std::cout << sum(a, n) << std::endl;
}
