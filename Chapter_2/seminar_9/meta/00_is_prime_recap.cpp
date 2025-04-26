template < unsigned int p, unsigned int d >
struct Check_Is_Prime 
{
	static constexpr bool value = 
		(p % d != 0) && Check_Is_Prime < p, d - 1 > ::value;
};

template < unsigned int p >
struct Check_Is_Prime < p, 2 > 
{
	static constexpr bool value = (p % 2 != 0);
};

template < unsigned int p >
struct Is_Prime 
{
	static constexpr bool value = Check_Is_Prime < p, p / 2 > ::value;
};

template <>
struct Is_Prime < 0 > { static constexpr bool value = false; };
template <>
struct Is_Prime < 1 > { static constexpr bool value = false; };
template <>
struct Is_Prime < 2 > { static constexpr bool value = true; };
template <>
struct Is_Prime < 3 > { static constexpr bool value = true; };

#include <iostream>

int main(){
    std::cout << Is_Prime<62>::value << std::endl;
}

// Такая шаблонная рекурсия -- это аналог цикла for
// при рассмаотрении программ времени компиляции

// Вообще есть некоторая техника, как именно переводить
// одни программы в другие
