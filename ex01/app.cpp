#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define SPACES " \n\t\r\f\v"

#include <sstream>
static std::string	read_from_input(bool digit)
{
	std::stringstream input;
	int			s, e;

	do
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
			std::exit(0);
		input.ignore()
		
			
		if (digit && input.find_first_not_of("0123456789") > - 1)
			digit = false;

	}
	while (input.empty() || !digit);
	return (input);
}

static void	add_contact(PhoneBook *pb)
{
	std::string	input[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Enter contact " << input[i] << ' ';
		input[i] = read_from_input(i == 3);
		if (input[i].length() > 10)
		{
			input[i].resize(10);
			*(input[i].end() - 1) = '.';
		}
	}
	pb->addContact(input);
}

static void	search_contact(PhoneBook *pb)
{
	const Contact	*contact;
	std::string input;

	std::cout << "search for contact by index: ";
	input = read_from_input(true);
	contact = pb->searchContact(std::stoi(input));
	if (!contact)
		std::cout << "invalid index" << std::endl;
	else
		contact->printContact();
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string input;

	std::cout << "Welcome to PhoneBook" << std::endl;
	do
	{
		std::cout << "Enter a COMMAND <ADD> <SEARCH> <EXIT>: ";
		input = read_from_input(false);
		std::cout << input << std::endl;
		if (input == "ADD")
			add_contact(&phoneBook);
		else if (input == "SEARCH")
			search_contact(&phoneBook);
	}
	while (input != "EXIT");
	return (0);
}