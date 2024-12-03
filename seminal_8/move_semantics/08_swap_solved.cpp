#include <iostream>

// a и b -- это lvalue внутри функции swap. Поэтому никаких move операций не вызвалось
// Для использования move операций нужно сделать явное преобразование

template<typename T>
void swap(T& a, T&b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

// При после применения std::move() формально a остается в непредсказуемом состоянии
// Но на следующей строчке мы его определеяем
// А в конце tmp нам и не нужно опеределять, поскольку нам этот объект не нужен
// и он "правильно умрёт"

template<typename MyClass>
class ScopedPointer {
	MyClass *ptr_;
public:
	ScopedPointer(MyClass *ptr = nullptr) : ptr_(ptr) {
    }

	~ScopedPointer() { 
        delete ptr_; 
    }

	ScopedPointer(const ScopedPointer& rhs) : 
		ptr_(new MyClass{*rhs.ptr_}) {
            std::cout << "Copy Ctor with copy and allocation" << std::endl;
        }
	
	ScopedPointer& operator=(const ScopedPointer& rhs) {
		if (this == &rhs) return *this;
		delete [] ptr_;
		ptr_ = new MyClass{*rhs.ptr_};
        std::cout << "Optor = with copy and allocation" << std::endl;
		return *this;
	}

    ScopedPointer(ScopedPointer && rhs): ptr_(rhs.ptr_) {
        rhs.ptr_ = nullptr;
        std::cout << "Move Ctor without copy and allocation" << std::endl;
    }

    ScopedPointer& operator=(ScopedPointer && rhs){
        delete ptr_;
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
        std::cout << "Move Assign without copy and allocation" << std::endl;
        return *this;
    }
};


int main() {
    ScopedPointer<int> p1{new int{10}};
    ScopedPointer<int> p2{new int{20}};
    swap(p1, p2);
}

// ВАЖНО: есть move операций нет, даже при использовании T&& будут 
// использоваться обычные конструкторы копирования и операторы присваивания