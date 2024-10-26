#include <iostream>

template<typename MyClass>
class ScopedPointer {
	MyClass *ptr_;
public:
	ScopedPointer(MyClass *ptr = nullptr) : ptr_(ptr) {
        std::cout << "Ctor" << std::endl;
    }

	~ScopedPointer() { 
        delete ptr_; 
        std::cout << "Dtor" << std::endl;
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

    // move constructor
    // реализуем то, что мы хотели (скопировать указатель)
    ScopedPointer(ScopedPointer && rhs): ptr_(rhs.ptr_) {
        rhs.ptr_ = nullptr;
        std::cout << "Move Ctor without copy and allocation" << std::endl;
    }

    // и все: никакого глубокого копирования с вделением памяти
    // случилось как будто "перемещение" данных из одного объекта в другой
    
    // Отличие от конструктора копирования:
    // При использовании конструктора копирования у нас есть гарантия того, 
    //        что объекты после копирования будут идентичны

    // При использовании move конструктора у нас такой гарантии нет! 
    //        rhs остается в консистентном, но НЕПРЕДСКАЗУЕМОМ состоянии

    // В нашем случае rhs остатся в нулевом состоянии (занулили указатель)

    // move assing
    // move constructor
    // реализуем то, что мы хотели (скопировать указатель)
    ScopedPointer& operator=(ScopedPointer && rhs){
        delete ptr_;
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
        std::cout << "Move Assign without copy and allocation" << std::endl;
        return *this;
    }
    // При использовании move aasign 
    //     rhs остается в консистентном, но НЕПРЕДСКАЗУЕМОМ состоянии
};


// посмотрим на тот же кусок кода

ScopedPointer<int> foo() {
    ScopedPointer<int> res{new int{30}};
    return res;
}

int main() {
    ScopedPointer<int> p1{new int{10}};
    ScopedPointer<int> p2{new int{20}};

    std::cout << "Глубокое копирование" << std::endl;
    p1 = p2;
    std::cout << "Глубокое копирование всё" << std::endl;

    std::cout << "Перемещение" << std::endl;
    p1 = foo();
    std::cout << "Перемещение всё" << std::endl;
}

// Ecли у типа есть move консруктор и move оператор присваивания, 
// то они будут вызывать всегда, когда в правой части стоит rvalue

// Если move операций нет -- увы, будет каждый раз глубокое копирование