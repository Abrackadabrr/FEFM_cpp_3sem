#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int *a = new int[n];
    a[0] = 1;
    a[1] = 2;
    a[3] = 3;
    // если вылезли несильно -- ничего и не заметите
    std::cout << a[48] << std::endl;
    // а если сильно -- ошибка сегментации памяти
    std::cout << a[]
    return 0;
}
