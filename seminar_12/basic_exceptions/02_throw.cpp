#include <iostream>

class PWrapper {
    int * p;
public:
    PWrapper(int value): p(new int{value}) {
        std::cout << "PWrapper Ctor: " << *p << std::endl;
    }
    ~PWrapper() {
        std::cout << "PWrapper Dtor: " << *p << std::endl;
        delete p;
    }
};

enum class error {
    N_IN_ZERO
};

void foonction(int n) {
    PWrapper p{n};
    if (n == 0) /* произошла ошибка */
        throw error::N_IN_ZERO;
        // и мы решили выкинуть код ошибки
    else foonction(n - 1);
    std::cout << "End of foonction(" + 
            std::to_string(n) << ") " << std::endl;
}

int main() {
    try {
        foonction(3);
    } 
    catch (const error & e) {
        std::cout << "Код ошибки: " << 
                static_cast<int>(e) << std::endl;
    }
}

// ПЕРВОЕ:
// В случае работы с исключениями 
// осуществляется как бы "корректный"
// выход из функции, которая это исключение
// выкинула в смысле отработанных деструкторов

// ВТОРОЕ:
// Исключение ловится выше по стеку вызовов 
// относительно места своего вылета,
// при этом оно летит "разматывая стек" 
// (и вызывая при этом деструкторы)

// ТРЕТЬЕ:
// Ключевое слово throw обозначает "создай объект
// исключения и начни раскрутку стека".