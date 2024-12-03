#include <iostream>
#include <stdlib.h>

// общее правило для низкоуровневой инициализации
// pointer_name = (cast-type*) malloc(size);

struct Person {
	int id
	char name[64];
};

int main() {
	// аллокация одного элемента в куче
	// во время присвоения происходит явное преобразование типов void * -> Person *
	Person *pPerson = (Person *)malloc(1 * sizeof(Person));
	if (pPerson == NULL) {
		std::cout << "Heap is ill" << std::endl;
		return 0;
	}

	std::cout << pPerson->id << std::endl;

	free(pPerson);
	return 0;
}
