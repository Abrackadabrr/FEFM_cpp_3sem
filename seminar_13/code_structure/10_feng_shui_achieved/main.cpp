#include <iostream>

#include "cow.hpp"
#include "dog.hpp"
#include "crazy_dog.hpp"

using namespace std;

// 
int main() {
    Animal* animals[3];
    animals[0] = new Cow();
    animals[1] = new Dog();
    animals[2] = new CrazyDog();

    cout << boolalpha;
    for(int i = 0; i < 3; i++) {
        cout << "Animal[" << i << "] has brain? " << animals[i]->hasBrain() << endl;
        cout << "Animal[" << i << "] says: ";
        animals[i]->say();
        delete animals[i];
    }

    return 0;
}
