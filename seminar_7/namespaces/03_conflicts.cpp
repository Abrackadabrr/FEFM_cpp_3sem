#include <iostream>

// давайте объявим структуру (возможно она будет объявлена даже не вами и в другом файле)
struct cout {
	int a;
	int b;
};

// .... too much code .... and too much files too much import .... //

using namespace std; 
// "вываливаем" все функции из просранства имён std в глобальное

int main() {
	cout << "Hello, World!" << endl;  // too much pain
}
