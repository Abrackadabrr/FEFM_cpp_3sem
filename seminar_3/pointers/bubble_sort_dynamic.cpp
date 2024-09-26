#include <iostream>

int main(int argc, char ** argv)
{
	int n;

	std::cin >> n;

	int * a = new int[n];

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

	delete[] a;

	return 0;
}
