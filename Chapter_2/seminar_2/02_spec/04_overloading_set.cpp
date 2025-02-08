// Вставим шаблоны в разрешение перегрузки
// "Последовательность разрешения"
// 1) Точное совпадение (включая совпадение со ссылкой)
// 1.5) Шаблонные специализации (шаблонное совпадение всегда точно)
// 2) Стандартные преобразования
// 3) Пользовательское преобразование
// 4) Переменное число агрументов (в с++ фактически не используется)
// 5) Связывание для неправильных ссылок

// Правила:
// 1) Собрали все имена
// 2) Выкинули дурацкие варианты (невовпадение в количестве аргументов)
// 3) Если есть кто-то попадающий в пункт 1 из списка "Последовательность разрешения",
//    то в случае единственности он и вызывается
//    Если есть больше одного такого, то ошибка компиляции
// 4) Если нет подходящих под 1 пункт кандидатов, то идем в пункт 2 и далее аналогично

// Большой пример

#include <iostream>


// Класс для примера пользовательского преобразования
class MyInt {
  int a_;
public:
  MyInt(int a): a_(a) {};
};

// Поехали собирать overloading set
#ifndef N0
int foo(int x) { return 0; } 
#endif

#ifndef N1
int foo(const int &x) { return 1; }
#endif

#ifndef N2
template<typename T>
T foo(T x) { return 2; }
#endif

#ifndef N10
int foo(char x) { return 10; }
#endif

#ifndef N11
int foo(short x) { return 11; }
#endif

#ifndef N12
int foo(const char &x) { return 12; }
#endif

#ifndef N13
int foo(double x) { return 13; }
#endif


#ifndef N21
int foo(MyInt x) { return 21;}
#endif

#ifndef N31
int foo(...) { return 31; }
#endif

#ifndef N41
int foo(int &x) { return 41; }
#endif

int main() {
  std::cout << "result: " << foo(10) << std::endl;
  return 0;
}
