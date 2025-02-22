//  Посмотрим тонкости того, как 
// создается сотояние лямбда функции

#include <iostream>

int main() {
    int a = 10;
    double b = 100;
    
    const auto f_1 = [=](int t) { return t * a * b; };
    // [=] -- означает взять все имена переменных, объявленных выше
    // и СКОПИРОВАТЬ с теми же именами в сотсояние

    const auto f_2 = [&](int t) { return t * a * b; };
    // [&] -- взять все по ссылке

    int* a_ptr = new int[10000];
    a_ptr[9000] = 20;
    const auto f_3 = [&value = a_ptr[4]] (int a) { return a*value; };
    // [&value=a_ptr[4]]взять по ссылке и присвоить этому имя value 

    delete [] a_ptr;

    // Что выведется в консоль?
    std::cout << f_3(10) << std::endl;

    const auto f_4 = [&a, b] (int t) { return t * a * b; };
    // взять а по ссылке с тем же именем, взять b по значению с тем же именем

    // и так далее, можно комбинировать
}
