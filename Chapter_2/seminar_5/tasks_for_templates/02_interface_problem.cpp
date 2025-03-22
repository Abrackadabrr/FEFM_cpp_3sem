// Давайте задаимся вопросом о том, 
// как сделать статический интерфейс 
// для шаблонного класс

// Динамический интерфейс мы знаем как делать,
// а как сделать статический?

#include <iostream>
#include <vector>
#include <list>

template<typename Cont, typename Predicate>
bool check(const Cont& v, const Predicate& pred) {
    for (int i = 0; i < v.size(); i++) {
        if (pred(v[i]))
            return true;
    }
    return false;
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 345, 546, 2134, 6};
    std::list<int> l{1, 2, 3, 4, 5, 6, 345, 546, 2134, 6};
    
    std::cout << std::boolalpha << check(v, [](int a) { return a == 3;}) << std::endl;
//    std::cout << std::boolalpha << check(l, [](int a) { return a == 3;}) << std::endl;
}


// Сработает ли этот кусок кода для списка?