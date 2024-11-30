#include <stdexcept>
#include <iostream>

class MyError: public std::out_of_range { 
public:
    MyError(const char * value): std::out_of_range(value) {};  
};

class MyArray10 {
    int * p;
    static const int size = 10;
public:
    int get_value(int where) {
        if (where > size)
            throw MyError("out of range in MyArray10");
        return 0;
    }
};

int main() {
    MyArray10 arr{};
    try {
        arr.get_value(100);
    } 
    catch (MyError & e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::out_of_range & e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::logic_error & e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}

// А что если метод what сам выбрасывает исключени?
// Если в catch-блоке вылетает ещё одно исключение, 
// пока не обработано первое, то это сразу же std::terminate(), 
// то есть завершение работы лапками вверх.