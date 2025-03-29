#include <tuple>
#include <iostream>
#include "print_type.hpp"
#include "print_type.cpp"

// Давайте напишем поэлементый оператор вывода на экран

template<typename ... elem_t>
std::ostream& operator<<(std::ostream& os, const std::tuple<elem_t...>& t) {
    for (int i = 0; i < sizeof...(elem_t); i++) {
        os << std::get<i>(t) << ' ';
    }
    return os;
}

int main() {
    int r = 3;
    std::tuple t = std::make_tuple(1, 2.4, r);
 //   std::cout << t << std::endl;
    std::cout << type_name<decltype(t)>() << std::endl;

    // А если я хочу кортеж из ссылок?
    // std::tuple t_ref = std::make_tuple(1, 2.4, std::ref(r));
    // std::cout << type_name<decltype(t_ref)>() << std::endl;
    
    // Обратим внимание на то, что std::ref не храниться в кортеже,
    // тип там будет честной ссылкой
}
