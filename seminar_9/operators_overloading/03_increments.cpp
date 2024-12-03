#include <iostream>

template<typename MyClass>
class ScopedPointer {
	MyClass *ptr_;
public:
	ScopedPointer(MyClass *ptr = nullptr) : ptr_(ptr) {}

	~ScopedPointer() {}

    // синтаксис объявления пре-инкремента
    ScopedPointer& operator++();
    // синтаксис объявление пост-инкремента
    ScopedPointer operator++(int);
    // доп аргумент липовый, нужен чисто для разрешения перегрузки
};

// семантика пре-инкремента: сделать +1 и вернуть новое значение
template<typename T>
ScopedPointer<T>& ScopedPointer<T>::operator++() {
    std::cout << "pre" << std::endl;
    ptr_++;
    return *this;
}

// семантика пост-инкремента: сделать +1 и вернуть старое значение
template<typename T>
ScopedPointer<T> ScopedPointer<T>::operator++(int) {
    std::cout << "post" << std::endl;
    ScopedPointer<T> tmp = *this;
    ++(*this);
    return tmp;
}

int main() {
    int *p = new int[20];
    ScopedPointer<int> sp{&p[10]};
    sp++;
    ++sp;
    delete[] p;
}

// с операторами декремента ситуация совершенно аналогичная
