#include <iostream>

// разминка -- вспоминаем что такое наследование
// порядок вызова конструкторов и деструкторов
// виртуальный деструктор
// таблица виртуальных функций

struct Animal{
    // some fields
    Animal() {
        // some stuff
        std::cout << "Animal Ctor" << std::endl;
    }

    virtual void say() {
        std::cout << "(silience)" << std::endl;
    }
    
    virtual ~Animal() {
        // some stuff
        std::cout << "Animal Dtor" << std::endl;
    }
};

struct Dog: public Animal {
    // some fields
    Dog() {
        // some stuff
        std::cout << "Dog Ctor" << std::endl;
    }

    void say() override {
        std::cout << "Gav" << std::endl;
    }

    virtual ~Dog() {
        // some stuff
        std::cout << "Dog Dtor" << std::endl;
    }
};

struct Cat: public Animal {
    // some fields
    Cat() {
        // some stuff
        std::cout << "Cat Ctor" << std::endl;
    }
    ~Cat() {
        // some stuff
        std::cout << "Cat Dtor" << std::endl;
    }
};

struct CrazyDog: public Dog {
    int* ptr_;
    CrazyDog(): ptr_(new int[10]) {
        // some stuff
        std::cout << "CrazyDog Ctor" << std::endl;
    }

    void say() override {
        std::cout << "Super Gav" << std::endl;
    }

    ~CrazyDog() {
        delete [] ptr_;
        // some stuff
        std::cout << "CrazyDog Dtor" << std::endl;
    }
};

// что на экране?

int main() {
    Animal* cd = new CrazyDog{};
    std::cout << std::endl;
    cd->say();
    std::cout << std::endl;
    delete cd;
}
