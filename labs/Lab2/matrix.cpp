template<typename T>
class Matrix {
	vector<T> data;  // какой-то класс вектора: subvector или std::vector
	// предполагается, что хранение будет происходить в одном линейном массиве,
	// а не как с двойным указателем 
	// предполагается, что матрица хранится построчно (Row-Major Ordering)
	unsigned cols, rows;

public:
	// 1) Конструирование

	// создание матрицы, заполненных value
	Matrix(unsigned rows, unsigned cols, int value = 0);

	// создание единичной матрицы
	static Matrix Identity(unsigned rows, unsigned cols);

	// создание случайной матрицы с заданным детерминантом
	static Matrix getSpecificDeterminant(unsigned n, T determinant);
    
	// ... может быть какие-то ещё инициализации для удобства ... //

	// 2) Селекторы
	unsigned rows() const;
	unsigned cols() const;

	// ... любые "getters", которые вам удобны ... //

	// 3) Методы для разминки и проверки работы вычисления детерминанта

	Matrix& transpose();	// транспонирую себя
	Matrix transpose() const;   // копирую себя, транспонируют и возвращаю

	// 4) Доступ к элементам
	T& operator()(unsigned row, unsigned col) {}
	T operator()(unsigned row, unsigned col) const;
	// можете организовать его через operator [], но тогда вам нужен будет 
	// прокси-класс по типу Row, который обсуждали на паре

	// 5) Любые методы, которые вам будут удобны для работы с матрицей 
	// например, созданием подматрицы, перестановка строк (столбцов), умонжение строки (столбца) на число и так далее
};

int main() {
	Matrix<double> m1{10, 10};

}
// задача: посчитать детерминант матрицы