#include <iostream>

// У инициализации также есть специальная семантика --- это пользовательское преобразование
// Ключевое слово explicit блокирует неявное преобразование 

struct MyString {
	char *buf_; int len_;
	explicit MyString(int len) : buf_{new char[len]{}}, len_{len} {
		std::cout << "Ctor" << std::endl;
	}
	~MyString() {
		delete [] buf_;
	}
	MyString(const MyString & rhs) = delete;
	MyString& operator=(const MyString & rhs) = delete;

	const char * getBuf() {
		return buf_;
	}
};

void foo(MyString s) {
	std::cout << s.getBuf() << std::endl;
}

int main() {
	foo(3); // ошибка компиляции
	MyString s = 2; // ошбика компиляции тут есть следствие explicit. Он так же блокирует copy init
}
