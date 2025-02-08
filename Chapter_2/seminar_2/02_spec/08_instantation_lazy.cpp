#include <iostream>

// Давайте посмотрим на код
// Будет ли ошибка?

template<typename T, int N>
struct MyClass {
    T* ptr;
    T var;

    void insteresting_method() {
        T* ptr = new T[N];
        // ... some stuff ...
        delete[] ptr;
    }

    void say_hello() {
        std::cout << "template parameter: " << N << std::endl;
    }
};

int main() {
    MyClass<int, -2> p{};
    p.say_hello();
}
// Будет ошибка комплияции?

// Что можно сказать о процессе инстанцирования?
