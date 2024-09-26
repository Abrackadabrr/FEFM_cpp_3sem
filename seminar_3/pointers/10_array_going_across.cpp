#include <iostream>

// что будет на экране?

int main() {
    int n = 10;
    int *n_pointer = &n;

    int *p = new int[n];
    for (int i = 0; i < n; i++) 
        *(p + i) = i;
        // p[i] = i;

    *(p + (++(*n_pointer))-- / 2) = 123;

    for (int i = 0; i < *n_pointer; i++) 
        std::cout << *(p + i) << ' ';
    std::cout << std::endl;

    return 0; 
}
