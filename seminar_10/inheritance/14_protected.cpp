// У нас появляется ещё один модификатор типа
// protected -- "видно только наследнику"

struct Matrix {

protected:
    int row = 1;
    int col = 1;

    int n_elems() {return row * col;};
};

struct DiagonalMatrix: public Matrix {
    // something interesting

public:
    int n_elems_wrapper() {
        // доступ к полям родительского класса 
        // из класса - наследника
        int row_x_col = row * col;
        // доступ к методу родительского класса
        // из класса - наследника
        return n_elems();
    }
};

int main() {
    Matrix m{};
    // m.n_elems();  // ошибка: нет доступа извне
    // m.row = 3;
    // m.col = 3;

    DiagonalMatrix d{};
    d.n_elems_wrapper();
    d.n_elems();  // ошибка: нет доступа извне
    d.row = 3;
    // d.col = 3;  
}

// Итого три модификтатора доступа, которые имеют следующий смысл:

// public -- "мои поля и методы досутпны всем"
// protected -- "мои поля и методы доступны только наследникам"
// private -- "мои поля и методы дотупны только мне"


// При этом в public-унаследованных классах модификаторы сохраняют свой смысл:
// остаются такими же, как и в базовом классе. 

// А что, есть не public наследование? Да, есть
