#include <iostream>

int main() {
    int matrix[3][4] = { {1, 2, 3, 4}, 
                         {2, 3, 4, 5}, 
                         {3, 4, 5, 6} };
    std::cout << matrix[2][1] << std::endl;
}
