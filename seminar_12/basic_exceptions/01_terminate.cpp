#include <iostream>

class PWrapper {
    int * p;
public:
    PWrapper(): p(new int) {
        std::cout << "PWrapper Ctor" << std::endl;
    }
    ~PWrapper() {
        delete p;
        std::cout << "PWrapper Dtor" << std::endl;
    }
};

void foonction(int n) {
    PWrapper p{};
    if (n == 0) /* произошла ошибка */
        std::abort();
        // и мы решили экстренно завершить программу
    else foonction(n - 1);
}

int main() {
    foonction(3);
}



// При таком подходе у объектов 
// не вызовутся деструкторы, которые могут
// освобождать ресурсы и делать какую-то
// логически важную часть кода