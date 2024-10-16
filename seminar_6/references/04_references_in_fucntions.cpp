// Если тип данных большой, то можно передать по указателю его в функцию, 
// но тогда придется постоянно заниматься разименовыванием и проерной на NULL
// В этом смысле использование сслылок более прозрачное и безопасное


struct Point {
        double x, y;
};

struct Triangle {
        Point  pts[3];
};

// Проблема: копирование потенциально большого объекта --> долго
double square_v(Triangle t) {
       double sq = t.pts[0].x * (t.pts[1].y - t.pts[2].y) +
                t.pts[1].x * (t.pts[2].y - t.pts[0].y) +
                t.pts[2].x * (t.pts[0].y - t.pts[1].y);
        return std::abs(sq) / 2.0;

}


// Проблемы:
// 1) Потенциальное случайное изменение (решается добалением const в начало)
// 2) Неясно что передается в функцию: массив или указатель. 
// 	Это становится понятным только после просмотра внутрь кода
// 3) Ну и конечное же бесконечные проверки на NULL
double square_p(const Triangle* pt) {
// !!!!!!!!
	if (!pt) return -1;
// !!!!!!!!
	double sq = pt->pts[0].x * (pt->pts[1].y - pt->pts[2].y) +
                pt->pts[1].x * (pt->pts[2].y - pt->pts[0].y) +
                pt->pts[2].x * (pt->pts[0].y - pt->pts[1].y);
        return std::abs(sq) / 2.0;
}


// передача переменной по ссылке в функцию
double square_r(const Triangle &t) {
// t -- это ссылка на передаваемы аргумент из вызывающего кода
// фактически в нашем случае -- это ссылка на локальную переменную функции main

// таким образом мы: 
// 1) и переменную не копировали
// 2) и проверять на NULL не нужно (значит и сегфолты тоже не нужно будет ловит)
// 3) ясно, что именно передается в функцию -- одна переменная (а точнее сыылка на нее)
       double sq = t.pts[0].x * (t.pts[1].y - t.pts[2].y) +
                t.pts[1].x * (t.pts[2].y - t.pts[0].y) +
                t.pts[2].x * (t.pts[0].y - t.pts[1].y);
        return std::abs(sq) / 2.0;

}

int main() {
        Triangle t = {{0, 0}, {0, 1}, {1, 0}};
        // по значению
        double a = square_v(t);
        // по указателю
        double b = square_p(&t);

	// по ссылке: синтаксис такой же как и у передачи по значению
	double c = square_r(t);
}

