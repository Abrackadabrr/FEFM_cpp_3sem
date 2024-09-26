#include <iostream>
#include <typeinfo>
#include <type_traits>

int main() {
    int a[] = {0, 5, 3};
    int b[4] = {0, 0, 0, 0};
    int *p = a;
    int *p1 = new int[4];
//    a = p; // compilation error
//    b = p1; // даже так, несмотря на одинаковое количество выделенных байт

// а давайте посмотрим на реальные типы этих переменных
//    std::cout << typeid(p).name() << std::endl;
//    std::cout << typeid(p1).name() << std::endl;
//    std::cout << typeid(a).name() << std::endl;
//    std::cout << typeid(b).name() << std::endl;


// идея в том, что тип переменной а может быть приведен к int *, а наоборот --- нет
//    std::cout << std::is_convertible_v<int [2], int *> << std::endl;
//    std::cout << std::is_convertible_v<int *, int [2]> << std::endl;
    return 0;
}
// про приведение типов будет говорить на протяжении всего семестра, сегодня 1 раз)
