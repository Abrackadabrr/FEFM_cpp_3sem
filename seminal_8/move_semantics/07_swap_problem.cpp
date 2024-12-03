#include <iostream>

// Давайте попробуем реализовать теперь прострую вещь: хочу поменять местами два Pointer'a
// И я пишу swap

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

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

// 1) Нет move операторов
// 2) Есть  move операторы

// Что на экране?

int main() {
    ScopedPointer<int> p1{new int{10}};
    ScopedPointer<int> p2{new int{20}};
    swap(p1, p2);
}