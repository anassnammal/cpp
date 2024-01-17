#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string input;

	std::cout << "Phone Book $> ";
	while ((std::cin >> input) && input != "EXIT")
	{
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "\r";
	}

}