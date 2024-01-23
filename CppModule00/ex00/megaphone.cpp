#include <iostream>
#include <algorithm>

void	makeItLoud(char const **av, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		std::string msg(av[i]);
		std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
		std::cout << msg;
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
