#include <iostream>

struct File {
  int a;
  File(int a) : a{a} { std::cout << "File ctor" << std::endl; }
  virtual ~File() {}
};

struct InputFile : virtual public File {
  int b;
  InputFile(int b) : File(b * 2), b{b} {
    std::cout << "IFile ctor" << std::endl;
  }
};

struct OutputFile : virtual public File {
  int c;
  OutputFile(int c) : File(c * 3), c{c} {
    std::cout << "OFile ctor" << std::endl;
  }
};

struct IOFile : public InputFile, public OutputFile {
  int d;
  // явно вызываем конструктор у самого нижнего базового класса File
  IOFile(int d) :   // создается один объект общий для InputFile и OutputFile
  InputFile(d * 5), 
  OutputFile(d * 7), d{d} {
    std::cout << "IOFile ctor" << std::endl;
  }
};

int main() {
    IOFile f(11);
    std::cout << f.a << std::endl;
    std::cout << f.InputFile::a << std::endl;
    std::cout << f.OutputFile::a << std::endl;
}

// Обязательно конструировать виртуальный базовый класс первым в списке инициализации
// Это правило выполняется для всех виртуальных базовых классов, не обязательно для "самых нижних"

// Если вы не вызовете конструктор File при виртуальном наследовании,
// то будет очень странная ошибка компиляции.

// Если вдруг у самого нижнего базового класса есть конструктор по умолчанию,
// то он будет подставлен компилятором и без вашего участия как программиста

// Факт -- при множественном наследовании появляется ещё один "уровень косвенности", то есть переход по дополнительному указателю
// Факт2 -- при виртуальном наследовании ещё плюс один "уровень косвенности"