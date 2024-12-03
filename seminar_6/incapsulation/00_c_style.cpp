#include <iostream>


//  сделаем конструкцию треугольника в 2д на С

struct Point {
	double x, y;
};

struct Triangle {
	Point  pts[3];	
};

// вычисляем площадь --- необходимо написать функцию
// передача треугольника в функцию может происходить по значению и по указателю 

double square(const Triangle &t) {
       double sq = t.pts[0].x * (t.pts[1].y - t.pts[2].y) +
                t.pts[1].x * (t.pts[2].y - t.pts[0].y) +
                t.pts[2].x * (t.pts[0].y - t.pts[1].y);
        return std::abs(sq) / 2.0;

}

int main() {
	Triangle t = {{0, 0}, {0, 1}, {1, 0}}
	// по значению
	double a = square(t); 
	t.pts[0] = t.pts[1];
	// по указателю
	double b = square(&t);
}
