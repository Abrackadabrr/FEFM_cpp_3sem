#include <iostream>

// давайте объявим структуру (возможно она будет объявлена даже не вами и в другом файле)
struct cout {
	int a;
	int b;
};

// .... too much code .... and too much files too much import .... //

//using namespace std; 
// ничего не "вываливаем" из просранства имён std в глобальное

int main() {
	std::cout << "Hello, World!" << std::endl;  // too much pain
}
