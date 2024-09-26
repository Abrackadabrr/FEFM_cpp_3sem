#include <iostream>


struct IntArray{
    int n;
    int *pointer;
}
// сколько будет занимать эта структура в памяти?

void buildIntArray(IntArray *array, int n) {
    array->n = n;
    array->pointer = new int[n];
}

void deleteArray(IntArray *array) {
    delete[] array->pointer;
}

int main() {
    IntArray *array = new IntArray;
    (*array).n = 10;
    // array->n = 10; // делает то же самое
    buildIntArray(array, 123);
    deleteArray(array);
    return 0;
}
