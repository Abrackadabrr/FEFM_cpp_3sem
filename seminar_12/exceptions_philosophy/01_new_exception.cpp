#include <iostream>

template<typename T>
class Matrix {
    T *mas;
    unsigned int rows;
    unsigned int cols;

public:
    // new бросает std::bad_alloc, если невозможно 
    // выделить необходимый блок памяти  
    Matrix(int r, int c) : mas(new T[r * c]), rows(r), cols(c) {
        cout << "Ctor"<< endl;
    }

    // деструкторы всегда noexcept по умолчанию
    // если исключение вылетает в деструкторе, 
    // то это сразу же std::terminate()
    ~Matrix() {
        delete[] mas;
        cout << "Dtor"<< endl;
    }

    
};