#include <iostream>

struct Animal {
    // some fields
    Animal() {
        // some stuff
        std::cout << "Animal Ctor" << std::endl;
    }
};

struct Dog: public Animal {
    // some fields
    Dog() {
        // some stuff
        std::cout << "Dog Ctor" << std::endl;
    }
};

struct Cat: public Animal {
    // some fields
    Cat() {
        // some stuff
        std::cout << "Cat Ctor" << std::endl;
    }
};

struct CrazyDog: public Dog {
    // явно не прописываю консрукторы -> будут вызваны дефолтные конструкторы (без аргументов) 
    CrazyDog() {
        // some stuff
        std::cout << "CrazyDog Ctor" << std::endl;
    }
};

// что на экране?

int main() {
    CrazyDog cd{};
}