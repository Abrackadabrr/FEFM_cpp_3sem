// Наш ClassA захочет работать с ClassB, придётся его include-ить
#ifndef CLASS_A
#define CLASS_A
class ClassB;

class ClassA {
public:
	void describeSelf();

	void doSomething(ClassB* b);
};
#endif

#ifndef CLASS_B
#define CLASS_B
class ClassB
{
public:
    // Получаем ClassB, хотим с ним что-то сделать
    void doSomething(ClassA* b);

    // А это просто метод у нашего ClassA
    void describeSelf();
};
#endif 

void ClassB::doSomething(ClassA *a) {
	a->describeSelf();
}

void ClassB::describeSelf() { };
