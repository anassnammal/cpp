#include "Harl.hpp"

int main(int ac, char const**av)
{
	Harl	harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "USAGE: ./Harl [complain_level]" << std::endl;
    return (0);
}