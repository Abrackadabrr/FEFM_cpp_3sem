#include <iostream>

// У нас есть два механизма -- это переопределение и перегрузка

struct Matrix {
    virtual Matrix pow(int degree) {
        std::cout << "complex alghoritm" << std::endl;
        return Matrix{};
    }
};

struct DiagonalMatrix : public Matrix {
    // override -- ключевое слово, явно указывающее,
    // что эта функция ПЕРЕОПРЕДЕЛЯЕТ виртуальную функцию
    // из родительского класса
    Matrix pow(int degree) override {
        std::cout << "overrided" << std::endl;
        return Matrix{};
    }

    // при этом я могу как и обычно перегрузить 
    // функцию pow(int degree), все будет хорошо
    Matrix pow(long degree) {
        std::cout << "overloaded" << std::endl;
        return Matrix{};
    }
    // но она никогда не сможет быть вызвана по указателю на базовый класс
    // потому что она не заехала в таблицу виртуальных функций
};


int main() {
    Matrix* m_ptr = new DiagonalMatrix{};
    m_ptr->pow(3);
}
