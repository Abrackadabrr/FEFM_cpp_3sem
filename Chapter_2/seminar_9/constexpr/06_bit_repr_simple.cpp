#include <iostream>
#include <array>

// Оператор кавычки позволяет 
// добаваить к произвольному типу 
// произвольный постфикс, например "_binary"
#if 1
template<char... Chars> 
constexpr int operator "" _binary() {
    std::array<int, sizeof...(Chars)> arr{ Chars... };
    int sum = 0;
    for (auto c : arr)
        switch(c) {
            case '0': sum = sum * 2; break;
            case '1': sum = sum * 2 + 1; break;
            default: throw "Unexpected symbol";
        }
    return sum;
}
#endif

int main() {
    std::cout << 1010101010_binary << std::endl;
    // проверим, что эта штука не работает
    // на этапе компиляции
    constexpr unsigned value = 101010_binary;
}

// Давайте сделаем это на этапе компиляции
// Сначала нужно реализовать рекурсивную версию





#if 1
template<size_t N>
int get_sum(int past_sum, const std::array<char, N>& chars) {
    if  constexpr (N <= 0)
        return past_sum;
    else {
        std::array<char, static_cast<size_t>(N - 1)> from_second_to_last{};

        std::copy(chars.begin() + 1, chars.end(), from_second_to_last.begin());

        if (chars[0] == '1')
            return get_sum<N - 1>(past_sum * 2 + 1, from_second_to_last);
        else if (chars[0] == '0')
            return get_sum<N - 1>(past_sum * 2 + 0, from_second_to_last);
        else 
            throw "Bad char";
    }
}

template<char... Chars> 
int operator "" _binary() {
    std::cout << "Operator \"\" is called" << std::endl;
    std::array<char, sizeof...(Chars)> arr{ Chars... };
    return get_sum<sizeof...(Chars)>(0, arr);
}


#endif