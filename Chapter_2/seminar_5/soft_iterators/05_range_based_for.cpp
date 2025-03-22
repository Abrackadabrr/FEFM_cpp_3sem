#include <iostream>
#include <vector>
#include <list>

// В языке есть удобный синтаксис
// который называется range based for

template<typename Cont, typename Predicate>
bool check_smart(const Cont& v, const Predicate& pred) {
    for (auto element: v) {
        if (pred(element))
            return false;
    }
    return true;
}

// Как это расшифровывается??

/*

auto __begin = begin(v);
auto __end = end(v);

for (; __begin != end; ++__begin) {
    element = *__begin;

    ---- loop statement ---
}

*/

// cppinsights

int main() {
    std::list<int> l{1, 2, 3, 4, 5, 6, 345, 546, 2134, 6};

    std::cout << std::boolalpha << check_smart(l, [](int a) { return a == 3;}) << std::endl;
}

