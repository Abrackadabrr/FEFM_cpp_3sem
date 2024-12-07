// Хорошо, мы с научились отличать rvalue и lvalue. 
// А можно ли как-то самим сделать rvalue?
// Да, можно, это делается с помощью std::move()

#include <iostream>

int main() {
  int x = 4;
  int &&y = x + 1;

  int &&z = std::move(x); 
  // теперь мы формально считаем, что x -- это rvalue
  z = z + 1;
  y = y + 1;
  std::cout << x << " " << y << std::endl;
}

// std::move приводит тип T вашей переменной к типу T&& вот и все
// std::move это обычное преобразование типа, причем явное.
// Почему функция называется std::move() никому не известно