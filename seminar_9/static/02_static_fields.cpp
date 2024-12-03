// static поля --- это поля, для доступа к 
// комторым не нужен экземпляр класса

#include <iostream>
template<typename T>
class Vector3d {
	T x_, y_, z_;

public:
	Vector3d(T x = T{}, T y = T{}, T z = T{}): x_(x), y_(y), z_(z) {} 

	T getX() {return x_;}
	
	static const unsigned dimention = 3;
};

int main() {
	// для статических полей класс тоже можно считать как namespace
	std::cout << Vector3d<int>::dimention << std::endl;

	Vector3d<int> v1{0, 0, 1};
	Vector3d<int> v2{1, 0, 0};
	Vector3d<double> vd{1, 1, 1};
	// из экземпляров классов доступ тоже есть
	std::cout << v1.dimention << std::endl;
	std::cout << v2.dimention << std::endl;
	std::cout << vd.dimention << std::endl;
}
