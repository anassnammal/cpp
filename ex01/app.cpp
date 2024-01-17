#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string input;
	bool		finished;

	finished = false;
	while (!finished)
	{
		std::cout << "Phone Book $> ";
		if (!(std::cin >> input))
			std::cout << std::endl;
		else if (input == "EXIT")
			finished = true;
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		
	}
	return (0);
}