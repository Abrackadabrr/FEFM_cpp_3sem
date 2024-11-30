#include <iostream>

class Error {
protected:
    const char * string;
public:
    Error(const char * value): string(value) {
        std::cout << "Error Ctor" << std::endl;
    }

    virtual const char * what() {return string;}
    virtual ~Error() {
        std::cout << "Error Dtor" << std::endl;
    };
};

class MathError: public Error {
public:
    const static int code = 0;
    MathError(const char * string): Error(string) {
        std::cout << "Math Error Ctor" << std::endl;
    }
    ~MathError() {
        std::cout << "Math Error Dtor" << std::endl;
    }

    const char * what() override {
        std::cout << "Code: " << code << std::endl;
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
        divide(1, 0);
    }
    catch (Error e) {
        std::cout << e.what() << std::endl;
        // Ловить по значению можно, но тогда 
        // поймается только базовая часть того, что летит,
        // а остальное "обрежется"

        // Например, тут нет доступа к полю code
        // Такие поведение называется object slicing
    }
}
