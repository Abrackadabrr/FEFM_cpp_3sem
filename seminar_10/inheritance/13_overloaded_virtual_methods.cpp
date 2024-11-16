#include <iostream>

struct Matrix {
    virtual Matrix pow(double degree) {
        std::cout << "general double alg" << std::endl;
        return Matrix{};
    }

    virtual Matrix pow(int degree) {
        std::cout << "general int alg" << std::endl;
        return Matrix{};
    }
};

struct DiagonalMatrix: public Matrix {
    Matrix pow(int degree) override {
        std::cout << "simple for diag matrix" << std::endl;
        return Matrix{};
    }
};

int main() {
    // вызываем методы по указателю на базовый класс
    Matrix* m_ptr = new DiagonalMatrix{};
    m_ptr->pow(2);
    m_ptr->pow(2.567);
    
    // вызываем методы через объект класса
    DiagonalMatrix d_matrix{};
    d_matrix.pow(3);
    d_matrix.pow(2.345);

    // что на экране?
}
