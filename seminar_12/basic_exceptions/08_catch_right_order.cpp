#include <iostream>

class Error {
protected:
    const char * string;
public:
    Error(const char * value): string(value) {}
    const char * what() {return string;}
};

class MathError: public Error {
public:
    MathError(const char * string): Error(string) {}
    const char * what() {
        std::cout << "Math Error" << std::endl;
        return string;
    }
};

double divide(double x, double y) {
    if (std::abs(y) < 1e-16)
        throw MathError("Division by zero");
    return x / y;
}

int main() {
    try {
        double res = divide(1, 0);
    }
    // Правильные catch блоки:
    // 1) От частного к общему
    // 2) Ловим по ссылке, или указателю
    catch (MathError& e) {
        std::cout << e.what() << std::endl;
    }
    catch (Error& e) {
        std::cout << e.what() << std::endl;
    }
}
