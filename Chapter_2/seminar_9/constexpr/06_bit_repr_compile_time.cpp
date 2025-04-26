#include <iostream>

#if 1
template<size_t N>
int get_sum(int past_sum, const std::array<char, N>& chars) {
    // Полная специаилазция по числу оставшихся битов
    // И по совместитеьлству конец рекурсии
    if  constexpr (N == 0)
        return past_sum;
    else {
      // Primary template
        std::array<char, static_cast<size_t>(N - 1)> from_second_to_last{};

        std::copy(chars.begin() + 1, chars.end(), from_second_to_last.begin());
      // Частисная специализация по значению нулевого char
        if (chars[0] == '1')
            return get_sum<N - 1>(past_sum * 2 + 1, from_second_to_last);
        else if (chars[0] == '0')
            return get_sum<N - 1>(past_sum * 2 + 0, from_second_to_last);
        else 
            throw "Bad char";
    }
    // Все return --это некоторая внутренняя переменная (value)
}
#endif

// primary template
template <int Sum, char... Chars> struct binparser;

// Специализация "0"
template <int Sum, char... Rest> struct binparser<Sum, '0', Rest...> {
  static constexpr int value = binparser<Sum * 2, Rest...>::value;
};

// Специализация "1"
template <int Sum, char... Rest> struct binparser<Sum, '1', Rest...> {
  static constexpr int value = binparser<Sum * 2 + 1, Rest...>::value;
};

// Специализация "Конец рекурсии"
template <int Sum> struct binparser<Sum> {
  static constexpr int value = Sum;
};

// binary suffix
template<char... Chars> static constexpr int operator "" _binary() {
  return binparser<0, Chars...>::value;
}

int main() {
  constexpr auto b = 11001010_binary;
  std::cout << b << std::endl;
}

// Круто, но мы потратили слишком много сил на это
// А можно просто запутить функцию на этапе копмпиляции?
