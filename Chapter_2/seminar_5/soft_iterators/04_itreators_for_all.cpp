
#include <iostream>
#include <vector>
#include <list>

// Давайте предположим, что у на есть вот такой вот код

template<typename T, typename Predicate>
bool check(const std::vector<T>& v, const Predicate& pred) {
    for (int i = 0; i < v.size(); i++) {
        if (pred(v[i]))
            return false;
    }
    return true;
}

// Как можно сделать так, чтобы сюда залезал любой контейнер?

template<typename Cont, typename Predicate>
bool check_smart(const Cont& v, const Predicate& pred) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (pred(*i))
            return false;
    }
    return true;
}

// Дополнительно мы избавились от доступа через [ ]

int main() {
    std::list<int> l{1, 2, 3, 4, 5, 6, 345, 546, 2134, 6};

    std::cout << std::boolalpha << check_smart(l, [](int a) { return a == 3;}) << std::endl;
}

// Кажется, что мы каждый раз пишем одно и то же внутри тела цикла
