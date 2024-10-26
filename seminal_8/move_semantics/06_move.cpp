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


ScopedPointer<int> foo() {
    return  ScopedPointer<int>{new int{30}};
}

int main() {
    ScopedPointer<int> p1{new int{10}};
    ScopedPointer<int> p2{new int{20}};

    // явно указали, что у нас справа стоит rvalue
    // теперь будет вызван move оператор присваивания
    std::cout << "Копируем" << std::endl;
    p1 = std::move(p2);
    std::cout << "Закончили копировать" << std::endl;    
    // вроде бы р2 остался жить, но он теперь в НЕПРЕДСКАЗУЕМОМ СОСТОЯНИИ
    // p2 можно использовать дальше, но перед этим нужно сделать его состяние определенным,
    // например, скопировать в него что-то
    p2 = foo();
    // .. p2 теперь ведет себя предсказуемо .. //
    // можно думать, что мы как бы сохранили имя, при этом значение у нас переместилось
    // и больше к нему доступа нет, а что лежит в p2 неизвестно
}
