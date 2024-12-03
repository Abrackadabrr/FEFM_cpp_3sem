#include <iostream>

struct MyClass {
	int a = 0;
	int b = 1;
	int c = 2;
};

template<typename T>
class ScopedPointer {
	T *ptr_;
public:
    // Конструктор
	ScopedPointer(T *ptr = nullptr) : ptr_(ptr) {}
	// Деструктор
    ~ScopedPointer() { delete ptr_; }

    // Консруктор копирования
	ScopedPointer(const ScopedPointer& rhs) : 
		ptr_(new T{*rhs.ptr_}) {}	
	
    // Оператор присваивания
    // Допустим мы забыли проверить на присваивание самому себе
	ScopedPointer& operator=(const ScopedPointer& rhs) {
		// сделаем вывод на экран указателя, который у нас сейчас есть
        std::cout << ptr_ << std::endl;
		delete ptr_;
		ptr_ = new T{*rhs.ptr_};
        // а теперь вывод указателя, который нам выдаи при следующем выделении
        std::cout << ptr_ << std::endl;
		return *this;
	}
};


int main() {
	ScopedPointer<MyClass> ptr(new MyClass{10, 20, 30});
    // тут происходит фейл с перевыделением памяти
	ptr = ptr;
}