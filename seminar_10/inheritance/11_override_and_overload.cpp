#include <iostream>

// У нас есть два механизма -- это переопределение и перегрузка
// Давайте попробуем их смешать

struct Matrix {
    virtual Matrix pow(int degree) {
        std::cout << "complex alghoritm" << std::endl;
        return Matrix{};
    }
};

struct DiagonalMatrix : public Matrix {
    Matrix pow(int degree) override {
        std::cout << "simple alghoritm" << std::endl;
        return Matrix{};
    }

    Matrix pow(long degree) {
        std::cout << "simple alghoritm" << std::endl;
        return Matrix{};
    }
};

// что будет в выводе?

// что будет в выводе, если явно 
// указать тип long у константы 3? 

int main() {
    Matrix* m_ptr = new DiagonalMatrix{};
    m_ptr->pow(3l);
}
