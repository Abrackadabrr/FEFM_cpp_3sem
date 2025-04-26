#include <iostream>
#include <array>

// А можно просто добавить constexpr

template<char... Chars>
constexpr int operator "" _binary() {
  std::array<int, sizeof...(Chars)> arr { Chars... };
  int sum = 0;
  for (auto c : arr)
    switch(c) {
      case '0': sum = sum * 2; break;
      case '1': sum = sum * 2 + 1; break;
      default: throw "Unexpected symbol";
    }
  return sum;  
}

// Как у нас получился std::array 
// на этапе компиляции?

int main() {
    constexpr unsigned value = 1110101010101101100101101_binary;
    std::cout << value << std::endl;
}
