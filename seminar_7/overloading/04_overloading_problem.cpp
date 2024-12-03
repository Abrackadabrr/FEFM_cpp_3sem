float foo(float a) {
	return 0;
}

double foo(double a) {
	return 1;
}

int main() {
	std::cout << foo(10) << std::endl; // какая функция вызовется?
}
