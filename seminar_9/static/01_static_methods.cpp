// static фунции --- это методы, которые не принимают первым аргументов неявный this
// а значит, static функции можно вызывать без экземпляра класса 

template<typename T>
class Vector3d {
	T x_, y_, z_;

public:
	Vector3d(T x = T{}, T y = T{}, T z = T{}): x_(x), y_(y), z_(z) {} 

	T getX() {return x_;}
	
	// у static методов тоже есть доступ к полям экземпляра класса
	static T getX(const Vector3d& v) {return v.x_;}

	static double squaredNorm(const Vector3d& v) {return v.x_ * v.x_+ v.y_ * v.y_ + v.z_ * v.z_;}

	// c помощтю статических методом можно сгенерировать другие "констркуторы" для вектора
	static Vector3d getFirstBasisVector() {
		return Vector3d{1, 0, 0};	
	}

	// почему не могу вот так написать: Vector3D() { ... } ?
	
	// ... 
};

int main() {
	// использование статических методов
	// имя_класса::название_метода
	Vector3d<int> v  = Vector3d<int>::getFirstBasisVector();
	v.getX();

	// можно считать, что для статических методов 
	// класс -- это просто namespace
}
