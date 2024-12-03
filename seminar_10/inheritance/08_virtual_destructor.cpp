#include <iostream>

struct Animal{
    // some fields
    Animal() {
        // some stuff
        std::cout << "Animal Ctor" << std::endl;
    }
    
    ~Animal() {
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
    ~Dog() {
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
    ~CrazyDog() {
        delete [] ptr_;
        // some stuff
        std::cout << "CrazyDog Dtor" << std::endl;
    }
};

// что на экране?

int main() {
    Animal* cd = new CrazyDog{};
    delete cd;
}
