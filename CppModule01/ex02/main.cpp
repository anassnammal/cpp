#include <iostream>

int	main(void)
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

	std::cout << &greeting << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << greeting << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return 0;
}
