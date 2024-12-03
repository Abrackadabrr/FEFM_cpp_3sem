struct Point2D {
	double x_, y_;
	
// и вот сгенерированное
// 	Point2D() : default-init x_, default-init y_ {}
//	~Point2D() {}
//	Point2D(const Point2D& rhs): x_(rhs.x_), y_(rhs.y_) {}
//	Point2D& operator=(const Point2D& rhs) {
//		x_= rhs.x_; y = rhs.y_; return *this;
//	}
}

// если x_ y_ это встроенные типы, то реализуется побитовое копирвоание в copy ctor и assign optpr

// если x_ y_ имеют более сложный тип с определенным оператором присваивания и копирующим конструктором,
// то в соотвествующих функциях они и будут вызваны

// ещё раз: это все генерирует компилятор

int main() {
	Point2D p1{}; // default init
	Point2D p2{p1}; // copy ctor
}
