#include <iostream>

unsigned long fib(int n) {
    unsigned long first = 0, second = 1, next;

    for (int i = 2; i < n; ++i) {
        next = first + second;
        first = second;
        second = next;
    }
    
    return second;
}

// Берем и параллелим задачу о числах фибоначи
// Взяли хороший код и ...

// ... сделали очень плохим

int main() {
    int n = 42;

    unsigned long first = 0, second = 1, next;

#pragma omp parallel for
    for (int i = 2; i < n; ++i) {
        next = first + second;
        first = second;
        second = next;
    }

    std::cout << second << std::endl;
    std::cout << fib(n) << std::endl;
    return 0;
}

// Проблемы в том, что итерации в цикле for 
// "имею зависимость по данным"

// Итреация i в цикле зависит от работы итерации i-1

// И здесь работает такой принцип
// "чтобы улучшить, надо ухудшить"

// Это общий принцип, который используется в парпроге
// Зачастую программы, оптимально работающие в последовательном
// режиме, не параллелятся от слова совсем.
// Фибонначи без рекурсии -- это пример такой штуки.
