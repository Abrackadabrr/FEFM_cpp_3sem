#include <iostream>
#include <array>
#include <iterator>
#include <type_traits>

template<typename Derived>
struct MatrixBase {

};

using u_int = unsigned int;
template<typename T, u_int N>
using Vector = std::array<T, N>;


template<typename T, u_int N>
std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec) {
    for (auto el : vec) 
        os << el << " ";
    return os;
}

template<typename T, u_int N>
class DiagonalMatrix {
    Vector<T, N> data;

public:
    DiagonalMatrix(Vector<T, N>&& l, bool trans = false): data(l) {}

    u_int storage_size() const { return N; };
    u_int rows() const { return N; };
    u_int cols() const { return N; };

    DiagonalMatrix<T, N>& transpose_inplace() {return *this;};
    DiagonalMatrix<T, N> transpose() const {return *this;}

    T& operator()(u_int i) {return data[i];};
    const T& operator()(u_int i, u_int j) const { return i == j ? data[i] : 0; };

    Vector<T, N> matvec(const Vector<T, N>& vector) const {
        Vector<T, N> result = vector;
        for (u_int i = 0; i < N; i++)
            result[i] *= data[i]; 
        return result;
    }
};

template<typename T, u_int N, u_int M>
class Matrix {
    std::array<std::array<T, M>, N> data;

public:
    Matrix(std::initializer_list<std::initializer_list<T>> listlist) {
        auto rows = (u_int)(listlist.begin())->size();
        auto cols = (u_int)listlist.size();
    
        for (u_int i = 0; i < rows; i++) {
            for (u_int j = 0; j < cols; j++) {
                data[i][j] = ((listlist.begin()+i)->begin())[j];
            }
        }
    }

    u_int storage_size() { return N * M; };
    u_int rows() { return N; }
    u_int cols() { return M; }

    Matrix<T, M, N> transpose() {
        Matrix<T, M, N> result;
        for (u_int i = 0; i < N; ++i)
            for (u_int j = 0; j < M; ++j) 
                result(j, i) = data[i][j];
        return result;
    }

    T& operator()(u_int i, u_int j) { return data[i][j]; };
    const T& operator()(u_int i, u_int j) const { return data[i][j]; };

    Vector<T, N> matvec(const Vector<T, M>& vector) const {
        Vector<T, N> result;
        std::fill(result.begin(), result.end(), 0);

        for (u_int i = 0; i < N; i++)
            for (u_int j = 0; j < M; ++j)
                result[i] += vector[j] * data[i][j]; 
        return result;
    }
};

template<typename Matrix, typename Vector, 
    typename T = std::void_t<decltype(std::declval<Matrix>().rows())>>
Vector foo(const Matrix& A, const Vector& b) {
    // solve Ax = b

    // в алгоритме точно где-то используется матвек
    auto res = A.matvec(b);

    return res;
}

int main() {
    int a = 4; int b = 5;
//    foo(a, b);
    Matrix<double, 2, 2> matrix{{{2, 1}, {1, 2}}};
    Vector<double, 2> vec{2, 1};
    const auto res = foo(matrix, vec);
}
