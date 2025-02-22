#include <iostream>

// Функторы можно куда-то передавать как объекты

class ConstantMultiplier{
    int a = 0;

public:
    ConstantMultiplier(int constant) { a = constant;};  // нормальный конструктор?
    int operator()(int b) {return b * a;}; 
};

template<typename Callable>
/*возвращаемое значение*/ invoke(const Callable& functor, /*аргументы какие-то*/) {
    // --- some stuff --- //
    return functor(/*аргументы какие-то*/);
};

// Что нужно написать в возвращаемое значение?
// Что нужно написать в аргументы?

int main() {
    ConstantMultiplier f_10(10);
    invoke(f_10, 10);
}

// Надо как-то понять, что мы будем передавать в шаблоны

// Пример не надуман, а имеет четкое и 
// понятное применение, например, интегрирование
