// Первым делом поговорим про функторы

#include <iostream>

class ConstantMultiplier{
    int a = 0;

public:
    ConstantMultiplier(int constant) { a = constant;};  // нормальный конструктор?
    int operator()(int b) {return b * a;}; 
};

int main() {

    ConstantMultiplier func_10(10);
    std::cout << func_10(5) << std::endl;

    ConstantMultiplier func_2(2);
    std::cout << func_2(10) << std::endl; 
}

// Функторы обобщают функции, принимая в себя некоторые 
// аргументы как СОСТОЯНИЕ. В этом их фича
