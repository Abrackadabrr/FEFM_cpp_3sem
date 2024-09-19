#include <iostream>

int main()
{
	const unsigned size = 10;

	int a[size];

	std::size_t n;

	std::cin >> n;

	if (n > size)
	{
		std::cerr << "Too many elements.\n";

		return 0;
	}

	for (std::size_t i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}

	for (std::size_t i = 0; i < n - 1; ++i)
	{
		for (std::size_t j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j])
			{
				int tmp = a[j];
				a[j] = a[i];
				a[i] = ;
				// std::swap(a[i], a[j]);
			}
		}
	}

	for (std::size_t i = 0; i < n; ++i)
	{
		std::cout << a[i] << ' ';
	}
	
	return 0;
}
