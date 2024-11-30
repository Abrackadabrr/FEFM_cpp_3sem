#include <iostream>

const int DIVIZION_BY_ZERO = 0;

double divide(double x, double y) {
    if (std::abs(y) < 1e-16)
        throw DIVIZION_BY_ZERO;
    return x / y;
}

int main() {
    try {
        double res = divide(1, 0);
    }
    // Catch блоки пробуются в порядке их написания в коде
    catch (int * e) {
        // Не совпадает тип => ничего не поймали
        std::cout << "int * e: " << e << std::endl;
    }
    catch (long e) {
        // Запрещены преобразования типов, 
        // поэтому тоже не поймали
        std::cout << "long e: " << e << std::endl;
    }
    // Остальные блоки смогут поймать исключение типа int
    catch (int & e) {
        std::cout << "int & e: " << e << std::endl;
    }
    catch (int e) {
        std::cout << "int e: " << e << std::endl;
    }
    catch (const int & e) {
        std::cout << "const int & e: " << e << std::endl;
    }
}


// Бросать исключеният типа int довольно
// грустно, потому что они как будто 
// сообщают нам об ошибке слишком мало

// При большом количестве ошибкок нам может ещё
// понядобиться их разделение на подтипы