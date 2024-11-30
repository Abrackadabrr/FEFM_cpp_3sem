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

    // а давайте напишем свой swap 
    // и используем его для копирования
    void swap(Matrix & lhs, Matrix & rhs) noexcept {
        std::swap(lhs.mas, rhs.mas);
        std::swap(lhs.cols, rhs.cols);
        std::swap(lhs.rows, rhs.rows);
    }

public: 
    Matrix(int r, int c) : mas(new T[r * c]), rows(r), cols(c) {}

    ~Matrix() {
        delete[] mas;
    }

    Matrix(const Matrix &rhs): mas(copy(rhs.mas, rhs.rows, rhs.cols)), rows(rhs.rows), cols(rhs.cols) {}

    // для строгой гарантии безопасности достаточно,
    // чтобы в методе можно было бы провести черту,
    // такую что выше неё состояние класса не изменяется,
    // а ниже неё не выбрасываются исключения
    Matrix& operator=(const Matrix& rhs) {
        Matrix tmp(rhs);   // тут исключения
    // ----------------------------- //
        swap(*this, tmp);  // тут изменение состояния
        return *this;
    }
};
