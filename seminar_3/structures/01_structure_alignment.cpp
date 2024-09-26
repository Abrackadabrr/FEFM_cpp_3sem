#include <iostream>

struct X {
    char c1;
    char c2;
    char c3;
    int i1;
    int i2;
};

struct X_reordered {
    char c1;
    int i1;
    char c2;
    int i2;
    char c3;
};

struct x_bool {
    bool b1;
    bool b2;
    bool b3;
    bool b4;
};

struct x_char {
    char c1;
    char c2;
    char c3;
    char c4;
};

int main(){
    std::cout << "sizeof(X): " << sizeof(X) << std::endl;
    std::cout << "alignof(X): " << alignof(X) << std::endl;
    std::cout << "sizeof(X_reordered): " << sizeof(X_reordered) << std::endl;
    std::cout << "alignof(X_reordered): " << alignof(X_reordered) << std::endl;
    std::cout << "sizeof(x_bool): " << sizeof(x_bool) << std::endl;
    std::cout << "alignof(x_bool): " << alignof(x_bool) << std::endl;
    std::cout << "sizeof(x_char): " << sizeof(x_char) << std::endl;
    std::cout << "alignof(x_char): " << alignof(x_char) << std::endl;
}
