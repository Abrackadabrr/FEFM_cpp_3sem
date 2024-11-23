#include <iostream>

template<typename T>
class subvector{
    int top = 0;
    int capacity;
    T* ptr;

public:
    subvector(int capacity_): capacity(capacity_), ptr(new T[capacity]) {}

    // правильно ли реализован оператор перемещающего присваивания?
    subvector& operator=(subvector&& rhs) {
        std::swap(ptr, rhs.ptr);
        std::swap(top, rhs.top);
        std::swap(capacity, rhs.capacity);
        retrun *this;
    }
};


int main() {
    subvector<int> v1{10};
    v1 = std::move(v1); // ????
}
