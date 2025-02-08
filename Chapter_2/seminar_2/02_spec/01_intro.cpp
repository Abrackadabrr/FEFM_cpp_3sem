#include <iostream>

// Давайте писать шаблонный компаратор, 
// который будет содержать в себе специализации для некоторых
// необычных классов
template<typename T>
bool less(T lhs, T rhs) {
    return lhs < rhs;
}

// Синтаксис объявления специализации следующий
template<>
bool less(int lhs, int rhs){
    std::cout << "lol" << std::endl;
    return true;
}

int main() {
    std::cout << std::boolalpha << 
        ((less<float>(5.0, 4.0)) == (less<int>(5, 4))) << std::endl;
}



// Давайте обсудим как вообще появляются функции,
// описанные в шаблонах: инстранцирование
