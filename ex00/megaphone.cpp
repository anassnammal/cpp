#include <iostream>
#include <string>
#include <iomanip>

void	makeItLoud(char const **av, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::setiosflags(std::ios::uppercase);
		std::cout << av[i];
	}
}

int main(int ac, char const **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		makeItLoud(av + 1, ac - 1);
	std::cout << std::endl;
	return 0;
}
