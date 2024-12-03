// Теперь обсудим move семантику в С++
// Сначала давайте все же придумаем ей место, зачем она вообще появилась

#include <iostream>

template<typename T>
class vector {
	T *ptr_;
    int size_;
    int capacity_;
public:
    // Конструктор
	vector(int capacity = 0) : ptr_(new T[capacity]), size_(0), capacity_(capacity) {
        std::cout << "Ctor" << std::endl;
    }
	// Деструктор
    ~vector() { 
        delete ptr_;
        std::cout << "Dtor" << std::endl;
    }

    // Консруктор копирования
	vector(const vector& rhs) {
            // выделение памяти
            ptr_ = new T[rhs.capacity_];
            for (int i = 0; i < rhs.size_; i++)
            // поэлементное копирование
                ptr_[i] = rhs.ptr_[i];
            std::cout << "Copy Ctor: use memory allocation and type T copying (size) times" << std::endl;
        }	
	
    // Оператор присваивания
	vector& operator=(const vector& rhs) {
		if (this == &rhs) return *this;
		delete ptr_;
        // выделение памяти
        ptr_ = new T[rhs.capacity_];
            for (int i = 0; i < rhs.size_; i++)
            // поэлементное копирование
                ptr_[i] = rhs.ptr_[i];

        std::cout << "Assign optor: use memory allocation and type T copying (size) times" << std::endl;

		return *this;
	}
};

// Конструктор копирования и оператор присваивания создают полнyю 
// копию из переданного объекта rhs.

// Это называется глубоким копированием: 
// после приваивания (копирования) объект полность 
// идентичен объекту справа от знака = (аргумента конструктора).

// Это отлично получилось сделать в прошлый раз с помощью 
// контрукторов копирования и операторов присваивания.

// Пусть теперь есть функция, которая возвращает экземпляр объекта vector
vector<int> foo() {
    vector<int> res{20};
    // ..filling.. //
    return res;
}

// И посмотрим на следующий код

int main() {
    vector<int> v1{10};
    vector<int> v2{20};

    // ... filling vetors... //

    std::cout << "Хотим глубокое копирование" << std::endl;
    v2 = v1;
    // вот тут я действительно хочу глубокое копирование

    // ...some code... //

    std::cout << "Не хотим глубокое копирование" << std::endl; 
    v1= foo();  
    std::cout << "Нежелательное глубокое копирование закончилось" << std::endl;

    // хочу ли я здесь глубокое копирование?
    // кажется, что нет, поскольку функция foo() вернет объект, 
    // который присвоится и умрет в этой же строчке кода

    // тут происходит большой перерасход 
    // Объект foo() умирает в конце полного выражение, он есть временный объект. 
    // А мы зачем-то обходимся с ним так, как будто он нам нужен где-то дальше по коду

    // Нам было бы удобно просто скопировать указатели, а указатели foo()
    // занулить и дать ему спокойно умереть в конце строчки
}