#include <iostream>

// указатель можно использовать как на чтение, так и на запись. Нужно поставить заборчики для людей, чтобы случайно ничего не изменилось в коде
void function(int *a) {
    // а почему бы нам не поменять значение случайно?
    a[4] = 0;
    std::cout << a[3] << std::endl;
}

// решение проблемы --- это константный указатель, по которому нельзя менять данные.

void const_function(const int *a) {
    // в одной из следующих строк будет ошибка компиляции, в какой из них?
    // a = a + 1;
    a[4] = 0;
    std::cout << a[3] << std::endl;
}

int main() {
    int a[4] = {0, 1, 2, 3};
    int *a_dyn = new int[2];

    function(a);
    function(a_dyn);
    const_function(a);
    const_function(a_dyn);

    return 0;
}
