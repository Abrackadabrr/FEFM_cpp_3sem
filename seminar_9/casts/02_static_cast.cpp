// для фундаметнальных типов правила static_cast лежат внутри комплятора
// для пользовательских типов консруктор задает явное преобразование 

#include <iostream>

struct T {};

struct S{
    S(const T& t) {
        std::cout << "S(const T&)" << std::endl;
    }
};

void foo(const S&) {
    return;
}

int main() {
    T t{};
    S s = static_cast<S>(t);
    foo(static_cast<S>(t));
    foo(t);
}
