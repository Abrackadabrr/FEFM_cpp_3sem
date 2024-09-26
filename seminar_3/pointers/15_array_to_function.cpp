#include <iostream>

// указатель можно использовать как на чтение, так и на запись. Нужно поставить заборчики для людей, чтобы случайно ничего не изменилось в коде
void function(int *a) {
    // а почему бы нам не поменять значение случайно?
    a[4] = 0;
    std::cout << a[3] << std::endl;
}

void const_function(const int *a) {
    // a[4] = 0;
    std::cout << a[3] << std::endl;
}

int main() {
    // эти массивы почти идентичны и можно их оба передавать в 
    int a[2] = {0, 1};
    int *a_dyn = new int[2];

    function(a);
    function(a_dyn);
    const_function(a);
    const_function(a_dyn);

    return 0;
}
