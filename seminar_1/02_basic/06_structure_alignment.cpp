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

int main(){
    std::cout << "sizeof(X): " << sizeof(X) << std::endl;
    std::cout << "sizeof(X_reordered): " << sizeof(X_reordered) << std::endl;
    std::cout << "alignof(X): " << alignof(X) << std::endl;
    std::cout << "alignof(X_reordere): " << alignof(X_reordered) << std::endl;
}
