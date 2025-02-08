#include <iostream>

template<typename T>
struct Base {
    T value = 1;

    virtual void show_the_secret() {
        std::cout << value << std::endl;
    };
};

template<typename T>
struct Derived: public Base<T> {
    T another_value = 2;
    
    void show_the_secret() override {
        std::cout << value << std::endl;
        std::cout << another_value << std::endl;
    }
};

int main() {
    Derived<int> der{};
    der.show_the_secret();
}

// Для понимания наличия или отсуствия ошибок компиляции 
// попробуем скомпилировать этот код поэтапно
// используя уже имеющиеся знания про шаблоны

