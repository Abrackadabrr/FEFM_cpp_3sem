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

    T* copy*(const T* source, int rows, int cols) {
        T* mas = new T[rhs.rows * rhs.cols];
        try {
            for (int i = 0; i < rows * cols) 
                mas[i] = source[i];
        }
        // тут в аргументе стоит "...", потому что 
        // мы даже не представляем, что здесь можно поймать
        catch (...) {
            delete[] mas;
            throw;
            // throw без аргументов означать перевыбросить
            // исключение
        }
        return mas;
        // до return мы сможем добраться только если у нас
        // не вылетело исключение
    }

    // Теперь если что, то у нас нет никаких утечек памяти, 
    // при такой реализации копирования исключение вылетает в конструкторе
    // и объект просто не создается, а значит и удалять не надо
    Matrix(const Matrix &rhs): mas(copy(rhs.mas, rhs.rows, rhs.cols)), rows(rhs.rows), cols(rhs.cols) {}
};
