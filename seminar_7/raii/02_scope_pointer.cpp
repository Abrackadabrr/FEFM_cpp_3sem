#include <iostream>

struct MyClass {
	int a = 0;
	int b = 1;
	int c = 2;
};


class ScopedPointer {
	MyClass *ptr_;
public:
	ScopedPointer(MyClass *ptr = nullptr) : ptr_(ptr) {}
	~ScopedPointer() { delete ptr_; }

// просто так нельзя оставить: копирование и присваивание проблемно
	ScopedPointer(const ScopedPointer& rhs) : 
		ptr_(new MyClass{*rhs.ptr_}) {}
	// просто взяли и скопировали double	
	
	ScopedPointer& operator=(const ScopedPointer& rhs) {
		if (this == &rhs) return *this;
		delete [] ptr_;
		ptr_ = new MyClass{*rhs.ptr_};
		return *this;
	}
	
// оператор разыменовыния
         MyClass& operator*() const {
                  return *ptr_;
         }
  
// оператор стрелочки
	MyClass* operator->() {return ptr_;};
	const MyClass* operator->() const {return ptr_;}
// казалось бы, мы вернули указатель и потеряли ресурс. но нет
};


int main() {
	ScopedPointer ptr(new MyClass);
	std::cout << ptr->a << std::endl; 
}

// вызов стрелочки инициирует вызов струлочки у того объекта, который она вернула
// эта специфика поведения оператора стрелочки называется drill down поведением
