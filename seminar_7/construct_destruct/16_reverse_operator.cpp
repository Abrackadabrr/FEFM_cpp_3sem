#include <iostream>

// У инициализации также есть специальная семантика --- это пользовательское преобразование
// Ключевое слово explicit блокирует неявное преобразование 

struct MyString {
	char *buf_; int len_;
	MyString(int len) : buf_{new char[len]{}}, len_{len} {
		std::cout << "Ctor" << std::endl;
	}
	~MyString() {
		delete [] buf_;
	}
	MyString(const MyString & rhs) = delete;
	MyString& operator=(const MyString & rhs) = delete;

	operator const char *() {
		std::cout << "Optor myString -> const char *" << std::endl;
		return buf_;
	}
};

void foo(MyString s) {
	const char * str = s;
	std::cout << str << std::endl;
}

int main() {
	foo(3);
}
