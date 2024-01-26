#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	this->size = 0;
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void	PhoneBook::addContact(void)
{
	Contact	&c = this->contact[this->it];
	std::cout << "Enter contact First Name: ";
	c.setFirstName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Last Name: ";
	c.setLastName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Nick Name: ";
	c.setNickName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Phone Number: ";
	c.setPhoneNumber( PhoneBook::_prompt(true) );
	std::cout << "Enter contact Darkest Secret: ";
	c.setDarkestSecret( PhoneBook::_prompt(false) );
	this->size += (this->size < 8);
	++(this->it) %= 8;
}

std::string	PhoneBook::_prompt(bool d)
{
	std::stringstream	input_stream;
	std::string			input;
	std::string			parsed;


	std::getline(std::cin, input);
	if (!std::cin.good())
		std::exit(0);
	else if (!input.empty())
	{
		input_stream.str(input);
		while ((input_stream >> input))
			parsed += input + ' ';
		parsed.erase(parsed.end() - 1);
		if (d)
		{
			std::size_t p = parsed.find_first_not_of(" 0123456789");
			if (p != (std::size_t)-1) parsed.clear();
		}
	}
	return (parsed);
}

void			PhoneBook::printContact(Contact const & c)
{
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nick Name: " << c.getNickName() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

void			PhoneBook::listContact(void)
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < this->size; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->contact[i].getFirstName() << "|";
		std::cout << std::setw(10) << this->contact[i].getLastName() << "|";
		std::cout << std::setw(10) << this->contact[i].getNickName() << std::endl;
	}
}

void			PhoneBook::searchContact(void) const
{
	int			index;

	index = -1;
	while (index < 0 || index >= this->size)
	{
		do
			std::cout << "Enter index: ";
		while (!(std::cin >> index));
	}
	PhoneBook::printContact(this->contact[index]);
}