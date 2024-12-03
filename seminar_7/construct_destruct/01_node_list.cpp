class Node {
	int value_;
	Node* next_;

public:
	Node(int value) {
		value_ = value;
		next_ = nullptr;
	};
};

struct NodePublic {
	int a; 
	NodePublic* next;
	
	NodePublic() {
		a = 10;
		next = nullptr;
	}	

};

// когда вы определяете приватные поля, то у структуры ломается её классическая "агрегатная" инициализация
// когда вы определяете какой-то констркутор у структуры, то она тоже ломается
int main() {
	// Node node{0, nullptr} <--- теперь как нельзя собрать стуркутуру, так как наши поля привантые
	
	Node node1{0}; // direct init
	Node node2 = 0; //  copy init 

	NodePublic node3{1, nullptr};  // <-- сломается если раскоментировать конструктор
}
