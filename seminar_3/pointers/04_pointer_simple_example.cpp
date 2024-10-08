#include <iostream>
#include <sstream>
#include <ios>

// на самом деле int * --- это полноценный производный тип данный, называемый указателем
// в более общем виде его можно представить как "T *", где T --- это какой-то из фундаментальных или пользовательских типов данных (int, double, float).
// в переменной типа "T *" хранится "имя ячейки" (адрес ячейки) памяти в 16ричной системе счисления.

// что мы ожидаем от указателей? 
// 1) узнать адрес
// 2) получить доступ

// для этого есть соотсветвующие операции: 1) & и  2) * 

int main() {
    int x = 1, y = 2;
    int *ip;
    // ip имеет тип int *, ip - указатель на int
    ip = &x;
    // & - операция взятия адреса, теперь в
    // ip хранится адрес х; иначе говоря,
    // ip указывает на х
    y = *ip;
    // * - операция разыменования указателя, теперь y == 1.
    *ip = 0;
    // посмотрим, что теперь лежит в переменной x
    std::cout << (x == 0) << std::endl;

    std::cout << "Адрес переменной x: " << ip << std::endl;
    std::cout << std::dec << "Адрес переменной x: "  << (long int)ip << std::endl;
}

// мнемоническое правило: звездочка формально относится к типу int *, но обычно её пишут около названия переменной.
// это помогает формально прочитать это как int *p, то есть применение * к переменной p даёт int.
// а фактически p --- указатель на int. Это удобно для чтения более сложных конструкций
