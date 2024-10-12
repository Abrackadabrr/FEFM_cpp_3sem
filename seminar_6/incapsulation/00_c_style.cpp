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

double square(Triangle t) {
       double sq = t.pts[0].x * (t.pts[1].y - t.pts[2].y) +
                t.pts[1].x * (t.pts[2].y - t.pts[0].y) +
                t.pts[2].x * (t.pts[0].y - t.pts[1].y);
        return std::abs(sq) / 2.0;

}

double square(Triangle* pt) {
	double sq = pt->pts[0].x * (pt->pts[1].y - pt->pts[2].y) +
		pt->pts[1].x * (pt->pts[2].y - pt->pts[0].y) +
		pt->pts[2].x * (pt->pts[0].y - pt->pts[1].y);
	return std::abs(sq) / 2.0;
}

int main() {
	Triangle t = {{0, 0}, {0, 1}, {1, 0}}
	// по значению
	double a = square(t); 
	// по указателю
	double b = square(&t);

	// какие могу быть вопросы к таким функциям?
}
