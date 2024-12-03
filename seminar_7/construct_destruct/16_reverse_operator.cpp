#include <iostream>

// У инициализации также есть специальная семантика --- это пользовательское преобразование

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

// а как проеобразовать в фундаменьтальный тип, если я не могу дописать ему конструктор?
// ответ: нужно переопределить соотвествующий оператор
	operator const char *() {
		std::cout << "Optor myString -> const char *" << std::endl;
		return buf_;
	}
	
	operator int() {
		return 0;
	} 
};

void foo(MyString s) {
	const char * str = s;
	std::cout << str << std::endl;
}

int main() {
	foo(3);
}
