class MyClass {
	int a;
	int b;
	int c;
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
	
	ScopedPointer& (const ScopedPointer& rhs) {
		if (this == &rhs) return *this;
		delete [] ptr_;
		ptr_ = new MyClass{*rhs.ptr_};
		return *this;
	}
// как реализовать доступ?
// метод?
};
