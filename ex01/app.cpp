#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

static std::string	read_from_input(void)
{
	std::string input;

	do
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
			input = "EXIT";
		std::cin.clear();
		std::cin
	}
	while (input.empty());

	return (input);
}

static void	add_contact(PhoneBook *pb)
{
	(void)pb;
	std::cout << "add contact" << std::endl;
}

static void	search_contact(PhoneBook *pb)
{
	const Contact	*contact;
	std::string input;

	std::cout << "search for contact by index: ";
	input = read_from_input();
	// parse int
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

	do
	{
		input = read_from_input();
		if (input == "ADD")
			add_contact(&phoneBook);
		else if (input == "SEARCH")
			search_contact(&phoneBook);
	}
	while (input != "EXIT");
	return (0);
}