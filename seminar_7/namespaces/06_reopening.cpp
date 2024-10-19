#include <iostream>

// пространства имен можно открывать
namespace first {
	int a = 3;
}

namespace second{
	int a = 4;
}

// first::a и second::a --- это разные переменные


// пространтсва имен можно переоткрывать в любом файле с кодом, относящимуся к вашему проекту

namespace first{
	int b = 5;
}

int main() {
	std::cout << first::a << std::endl;
	std::cout << second::a << std::endl;
	std::cout << first::b << std::endl;
}
