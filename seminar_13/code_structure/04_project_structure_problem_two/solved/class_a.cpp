#ifndef CLASS_B
#define CLASS_B
class ClassA;

class ClassB {
public:
	void describeSelf();
	
	void doSomething(ClassA* a);
};
#endif


#ifndef CLASS_A
#define CLASS_A

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

void ClassA::doSomething(ClassB *b) {
	b->describeSelf();
}

void ClassA::describeSelf() { };

