#include <iostream>

// значение аргумента будет скопировано в функцию, и затем будет изменяться именно локальная переменная функции
void increasing_by_value(int x, int n) {
    for (int i = 0; i < n; i++)
        x++;
}

// с помощью указателя мы получаем достп к переменной "в обход её названия"
void increasing_by_pointer(int *x, int n) {
    for (int i = 0; i < n; i++)
        (*x)++;
}

int main() {
    int x = 1;
    increasing_by_value(x, 10);
    std::cout << "Передача по значению: " << x << std::endl;
    increasing_by_pointer(&x, 10);
    std::cout << "Передача по указателю: " <<  x << std::endl;
    return 0;
}
