#include <iostream>

template<typename T>
class Matrix {
    T *mas;
    unsigned int rows;
    unsigned int cols;

public: 
    Matrix(int r, int c) : mas(new T[r * c]), rows(r), cols(c) {}

    ~Matrix() {
        delete[] mas;
    }

    // может ли вылететь исключение?
    // чем плох такой копирующий констркутор?
    Matrix(const Matrix &rhs) {
        mas = new T[rhs.rows * rhs.cols];
        rows = rhs.rows;
        cols = rhs.cols;
        for (int i = 0; i < rows * cols; i++) 
            mas[i] = rhs.mas[i];
    }

    // что если вылетит исключение в копировании в середине выполнения функции?
    // мы получили так называему "небезопасность функции относительно исключений"
};
 