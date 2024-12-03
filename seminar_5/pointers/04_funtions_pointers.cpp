#include <iostream>

int foo(int) {
	return 0;		
}

// typedef --- кодовое слово в С для добавления синонимов к типу данных, то есть "дополнительных новых названий типа"
typedef int (*pointer_to_function_type) (int);
// using --- аналогично, но со своими плюшками из с++
using p_f_t = int (*)(int);

int main() {
	pointer_to_function_type foo_pointer = foo; 
	std::cout << foo_pointer(6) << ' ' << foo(6) << std::endl;
}
