#include <iostream>

/* 
    производные типы --- это указатели, ссылки, массивы
    int*
    int&
    int[8]
*/

// пользовательнские типы --- то, что создает пользователь: стуктура, класс, enum и так далее

struct UserStructure {
    int first_int;
    bool second_bool;
    long third_long;
};

int main() {
    UserStructure structure = {4, false, 2e10};
    // присваивание поля в структуру происходит через точку
    structure.first_int = 5;
    structure.second_bool = true;
    structure.third_long = 2300;
    // посмотрим на размер типа. что будет выведено на экран?
    std::cout << sizeof(structure) << std::endl;
    return 0;
}
