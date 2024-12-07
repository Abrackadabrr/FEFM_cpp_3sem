// Механизм условной компиляции, называемый стражом включения
// Эта штука используется препроцессором для того, чтобы 
// не включать один и тот же кусок кода два раза в итоговый бинарник,
// иначе у нас получится с вами redifinition of *name
#ifndef ANIMAL_H

// #define NAME без аргумента после означет просто 
// определеить имя. Мы явно показали, что оно уже ЕСТЬ
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
protected:
    bool brain;
public:
    Animal() {
        cout << "Animal created" << endl;
        this->brain = true;
    }

    virtual void say() = 0; // Виртуальный метод, реализация будет в дочерних классах

    // Все эти методы будут доступны в дочерних классах
    bool hasBrain() {
        return brain;
    }
};

#endif // #ifndef ANIMAL_H

// Так как включение раскрывается рекурсивно, то стражи включения #ifndef работают
