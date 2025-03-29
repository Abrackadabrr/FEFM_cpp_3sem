#include <iostream>

#include "../seq_containers/print_type.hpp"
#include "../seq_containers/print_type.cpp"

template<int N, typename T>
struct element_storage {
private:
	T value;
public:
	element_storage(T&& val) : value(std::forward<T>(val)) {}	

	const T& get() const { return value; }
};

template<int N, typename Head, typename ... Tail>
struct tuple_element : tuple_element<N+1, Tail...> , element_storage<N, Head>{
private:
	using tup_el = tuple_element<N+1, Tail...>;
	using stor = element_storage<N, Head>;
public:
	tuple_element(Head&& val, Tail&& ... others): tup_el(std::forward<Tail>(others) ...), stor(std::forward<Head>(val)) {}
};

template<int N, typename Head>
struct tuple_element<N, Head> : element_storage<N, Head>{
public:
	using stor = element_storage<N, Head>;

	tuple_element(Head && val) : stor(std::forward<Head>(val)) {};
};

template<typename ... Elements>
struct my_tuple: tuple_element<0, Elements...> {
private:
	using base = tuple_element<0, Elements...>;
public:
	my_tuple(Elements&& ... values) : base(std::forward<Elements>(values) ...) {}
};


namespace __detail {
	template<int N, typename T>
	const T& get_impl(const element_storage<N, T>& element) {
        std::cout << type_name<T>() << std::endl;
		return element.get();
	}
}

template<int N, typename ... elem_t>
decltype(auto) get(const my_tuple<elem_t...>& tup) {
	return __detail::get_impl<N>(tup);
}

struct tuple_like {
    int a;
    char c;
    double d;
};

int main() {
	std::string s{"Hello, World!"};
	my_tuple t{1, 'c', 3.4};
    std::cout << type_name<decltype(t)>() << std::endl;
//	std::cout << t.value << std::endl;
	std::cout << get<0>(t) << std::endl;
    std::cout << sizeof(decltype(t)) << std::endl;
    std::cout << sizeof(tuple_like) << std::endl;
}
