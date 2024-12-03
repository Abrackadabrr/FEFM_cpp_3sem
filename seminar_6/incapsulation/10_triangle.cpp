#include <iostream>
#include <cmath>
#include <iostream>

struct Point {
  double x, y;
};

struct Triangle {
  Point pts[3];

  // дописали конструктор к классу
  Triangle(const Point &p1, const Point& p2, const Point& p3) {
  	pts[0] = p1;
	pts[1] = p2;
	pts[2] = p3;
  }

  double square() const {
    double sq = pts[0].x * (pts[1].y - pts[2].y) +
                pts[1].x * (pts[2].y - pts[0].y) +
                pts[2].x * (pts[0].y - pts[1].y);
    return std::abs(sq) / 2.0;
  }
};

int main() {
  // создали констанстный объект, который нелья изменять
  const struct Triangle t{ {1.0, 1.0}, {3.0, 3.0}, {1.0, 2.0} };
  double square = t.square();
  std::cout << square << std::endl;
}
