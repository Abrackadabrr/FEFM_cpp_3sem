#include "matrix.cpp"

#define USE_VECTOR 0

#if USE_VECTOR
#include "subvector.cpp"
subvector multiply(const Matrix& m, const subvector& v) {
	subvector res{};
	for (int i = 0; i < m.get_rows(); i++) {
		double i_res = 0;
		for (int j = 0; j < m.get_cols(); j++)
			i_res += m(i, j) * v[i];
		res.push_back(i_res);
	}
	return res;
}
#endif 

int main() {
	Matrix m = Matrix::Identity(3);
#if USE_VECTOR
	subvector v{};
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
#endif 
	return 0;
}
