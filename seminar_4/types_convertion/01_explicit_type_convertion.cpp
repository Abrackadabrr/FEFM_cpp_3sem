#include <iostream>
using namespace std;

int main() {
  int int_var = 17;

  float float_var;

  float_var = float(int_var) / 2;
  // явно приводим переменную int_var к типу float и выполняем преобразование
  // если проигнорировать приведение, то получится неожиданный результат: целочисленное деление с отбрасыванием остатка

  float stupid_float = int_var / 2;

  cout << "The value of float_var is: " << float_var << endl;
  cout << "The value of stupid_float is: " << stupid_float << endl;

  char a = 'a';
  
  std::cout << "Output without convertion: " << a << std::endl;
  std::cout << "Output with convertion: " << int(a) << std::endl;
  
  return 0;
}

