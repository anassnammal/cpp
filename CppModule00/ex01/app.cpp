#include "PhoneBook.hpp"
#include <sstream>

static void	add_contact(PhoneBook *pb)
{
	std::string	input[5];
	std::string	info[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};

	for (size_t i = 0; i < 5; i++)
	{
		do
		{
			std::cout << BG_COLOR;
			std::cout << "Enter contact " << info[i];
			std::cout << BG_NOCLR << ' ';
			input[i] = read_from_input(i == 3);
		} while (input[i].empty());
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
	std::string		input;
	unsigned int	id;

	std::cout << BG_COLOR;
	std::cout << std::setw(10) << "Index"<< '|';
	std::cout << std::setw(10) << "first Name"<< '|';
	std::cout << std::setw(10) << "Last name"<< '|';
	std::cout << std::setw(10) << "Nickname"<< '|';
	std::cout << BG_NOCLR << std::endl;
	
	pb->printContacts();
	do
	{
		std::cout << BG_COLOR;
		std::cout << "search for contact by index:";
		std::cout << BG_NOCLR << ' ';
		input = read_from_input(true);
	} while (input.empty());
	id = std::atoi(input.c_str());
	contact = pb->searchContact(id);
	if (!contact)
		std::cout << "invalid index" << std::endl;
	else
	{
		std::cout << std::setw(10) << id << '|';
		contact->printContact();
	}
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string input;

	std::cout << "Welcome to PhoneBook" << std::endl;
	do
	{
		std::cout << BG_COLOR;
		std::cout << "Enter a COMMAND <ADD> <SEARCH> <EXIT>:";
		std::cout << BG_NOCLR << ' ';
		input = read_from_input(false);
		if (input == "ADD")
			add_contact(&phoneBook);
		else if (input == "SEARCH")
			search_contact(&phoneBook);
	}
	while (input != "EXIT");
	return (0);
}