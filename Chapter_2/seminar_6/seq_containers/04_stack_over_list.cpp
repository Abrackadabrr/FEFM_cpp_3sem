#include <stack>
#include <forward_list>
#include <iostream>

// Попробуем сделать стек на листе

int main() {
    std::stack<int, std::forward_list<int>> stack{};
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }

    while(stack.size()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
}
















// Адаптеры накладывают органичения на публичный интерфейс контейнеров
// Эту идею мы обсуждаем уже несколько семинаров: идея статического интерфейса
