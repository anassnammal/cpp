#include <iostream>
#include "Fixed.hpp"

int	main( void ) {
	Fixed a(5.25f);
	Fixed b(0.25f);
	std::cout << ((a + b - 0.5f) * 4 / 8 * 2) + 0.25f << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a - b << std::endl;

	return 0;
}