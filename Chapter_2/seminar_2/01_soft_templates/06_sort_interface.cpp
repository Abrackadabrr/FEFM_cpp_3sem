#include <algorithm>
#include <iostream>

// Генеротор массива в простейшем случае
template<typename T>
T* get_array(int n) {
    T* res = new T[n];
    for (int i = 0; i != n; ++i) {
        res[i] = T{n - i};
    }
    return res;
}

// Вывод массива на экран
template<typename T>
void print(const T* array, int n) {
    for (int i = 0; i != n; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

// Давайте попробуем сделать шаблонную сортировку
// Пусть есть сортировка пузырьком для интов
void sort(int * arr, int n) {
    for (int i = 0; i != n; ++i) {
        for (int j = i; j != n; ++j) {
            if (arr[j] < arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}
// Хотим обобищть на произвольный тип (float, double, string, MyClass)
// Что делаем?
// Шаг 1


int main() {
    int n = 10;
    int* array = get_array<int>(n);
    print(array, n);
    sort(array, n);
    print(array, n);
}
