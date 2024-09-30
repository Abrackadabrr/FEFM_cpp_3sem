#include <iostream>

int main() {
	int int_var = 128;
	float float_var = float(int_var);
	std::cout << float_var << std::endl;

	float f_v_1 = 123.34;
	int i_v_1 = int(f_v_1);

	float f_v_2 = 123.56;
	int i_v_2 = int(f_v_2);
	// округление вниз

	std::cout << i_v_1 << std::endl;
	std::cout << i_v_2 << std::endl;
}
