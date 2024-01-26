#include <iostream>
#include <string>

void	makeItLoud(std::string input)
{
	int	len = input.length();

	for (int i = 0; i < len; i++)
	{
		char &cur = input.at(i);
		cur = ::toupper(cur);
	}
	std::cout << input;
}	

int main(int ac, char const **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
			makeItLoud(av[i]);
	}
	std::cout << std::endl;
	return 0;
}
