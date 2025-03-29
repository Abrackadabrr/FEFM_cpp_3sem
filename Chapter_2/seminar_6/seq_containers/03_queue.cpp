#include <queue>
#include <iostream>
// Аналогично стеку есть адаптер очереди
// Идеология та же: сжать интерфейс
// queue -- FIFO, back(), front(), push(), pop()

int main() {
    std::queue<int> q{};
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }

    while(q.size()) {
        std::cout << q.front() << '\n';
        q.pop();
    }
}

// Очередь тоже сделана на деке, 
// но может быть сделана на любом из желаемых контейнеров

// За последствия никто не ручается