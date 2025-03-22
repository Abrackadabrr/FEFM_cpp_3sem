#include <vector>
#include <iostream>

// Давайте напишем обратный обход для контейнера


template<typename Iterable>
struct reverce_wrapper {
    Iterable& iterable;
};

template<typename Iterable>
decltype(auto) begin(reverce_wrapper<Iterable> w) {
    return rbegin(w.iterable);
} 

template<typename Iterable>
decltype(auto) end(reverce_wrapper<Iterable> w) {
    return rend(w.iterable);
}

int main() {
    std::vector v{1, 2, 3, 4, 5, 6, 7};
    for (const auto el: reverce_wrapper{v}) {
        std::cout << el << std::endl;
    }
}
