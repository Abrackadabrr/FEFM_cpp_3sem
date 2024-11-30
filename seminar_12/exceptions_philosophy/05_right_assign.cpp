template<typename T>
class Matrix {
    T *mas;
    unsigned int rows;
    unsigned int cols;

    T* copy(const T* source, int rows, int cols) {
        T* mas = new T[rhs.rows * rhs.cols];
        try {
            for (int i = 0; i < rows * cols) 
            mas[i] = source[i];
        }
        catch (...) {
            delete[] mas;
            throw;

        }
        return mas;

    }

public: 
    Matrix(int r, int c) : mas(new T[r * c]), rows(r), cols(c) {}

    ~Matrix() {
        delete[] mas;
    }

    Matrix(const Matrix &rhs): mas(copy(rhs.mas, rhs.rows, rhs.cols)), rows(rhs.rows), cols(rhs.cols) {}

    // простое переставление строчек позволяет нам сделать
    // строгую гарантию безопасности для такого оператора
    Matrix& operator=(const Matrix& rhs) {
        if (this == &rhs) return *this;
        T* tmp = copy(rhs.mas, rhs.rows, rhs.cols);
        delete[] mas;
        mas = tmp;
        top = rhs.top;
        capacity = rhs.capacity;
        return *this;
    }
};
