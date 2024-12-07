#ifndef CLASS_A_H
#define CLASS_A_H

class ClassB;

class ClassA
{
public:
    // Получаем ClassB, хотим с ним что-то сделать
    void doSomething(ClassB* b);

    // А это просто метод у нашего ClassA
    void describeSelf();
};

#endif
