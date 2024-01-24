#include "Harl.hpp"

int main(int ac, char const**av)
{
	Harl	harl;

	if (ac == 2)
		harl.complain(av[1]);
    return (0);
}