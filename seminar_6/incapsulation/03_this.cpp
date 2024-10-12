#include <cmath>
#include <iostream>

struct Point {
  double x, y;
};

struct Triangle {
  Point pts[3];
  double sqaure();
  // в функцию будто бы ничего не передается
  // давайте вспомним, как было в Си
  //
  // double square(const Triangle * t) {...};
  //
  // так как вся программа в итоге компилируется в машинный код, то там опять есть те же
  // ячейки памяти и адреса. поэтому на самом деле в эту функцию тоже передается кое какой указатель
}

double Triangle::square() {
    double sq = this->pts[0].x * (this->pts[1].y - this->pts[2].y) +
                this->pts[1].x * (this->pts[2].y - this->pts[0].y) +
                this->pts[2].x * (this->pts[0].y - this->pts[1].y);
    return std::abs(sq) / 2.0;
}

// this это как бы неявно передаваемый указатель на тот экзмепляр ккласса, который вызывает этот метод
// он опеределен в любом классе и указывает на этот экземпляр. пока что не пишите ничего через this-> 
// это излишне кроме одного случая


int main() {
  Triangle t;
  t.pts[0] = Point{1.0, 1.0};
  t.pts[1] = Point{3.0, 3.0};
  t.pts[2] = Point{1.0, 2.0};
  double square = t.square();
  std::cout << square << std::endl;
}
