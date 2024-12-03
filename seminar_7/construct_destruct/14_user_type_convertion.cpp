#include <iostream>

// У инициализации также есть специальная семантика --- это пользовательское преобразование
// 

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

	const char * getBuf() {
		return buf_;
	}
};

void foo(MyString s) {
	std::cout << s.getBuf() << std::endl;
}

int main() {
	foo(42); // случилось неявное преобразование типа int в тип MyString
}
