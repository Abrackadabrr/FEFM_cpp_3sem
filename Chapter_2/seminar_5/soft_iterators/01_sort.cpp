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
template<typename T>
void sort(T * arr, int n) {
    for (int i = 0; i != n; ++i) {
        for (int j = i; j != n; ++j) {
            if (arr[j] < arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

// Шаг 2
template<typename T>
void sort(T * begin, T* end) {
    for (T* forward_ptr = begin; forward_ptr != end; forward_ptr+=1) {
        for (T* ptr = forward_ptr; ptr != end; ++ptr) {
            if (*ptr < *forward_ptr) {
                std::swap(*ptr, *forward_ptr);
            }
        }
    }
}

// Шаг 3
template<typename T, typename Comparator>
void sort(T * begin, T* end, const Comparator& compare = std::less) {
    for (T* forward_ptr = begin; forward_ptr != end; forward_ptr+=1) {
        for (T* ptr = forward_ptr; ptr != end; ++ptr) {
            if (compare(*ptr,*forward_ptr)) {
                std::swap(*ptr, *forward_ptr);
            }
        }
    }
}

int main() {
    int n = 10;
    int* array = get_array<int>(n);
    print(array, n);
    sort(array, n);
    print(array, n);
}

// Наш код на указателях все ещё предполагает, что данные в памяти лежит последовательно
// Это верно, например, для контейнера std::vector
// А что если данные лежат непоследовательно в памяти, но семантически они последовательны
// Например, std::list
 