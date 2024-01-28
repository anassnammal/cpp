#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	this->size = 0;
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void			PhoneBook::addContact(void)
{
	Contact	&c = this->contact[this->it];
	std::cout << "Enter contact First Name: " << std::endl;
	c.setFirstName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Last Name: " << std::endl;
	c.setLastName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Nick Name: " << std::endl;
	c.setNickName( PhoneBook::_prompt(false) );
	std::cout << "Enter contact Phone Number: " << std::endl;
	c.setPhoneNumber( PhoneBook::_prompt(true) );
	std::cout << "Enter contact Darkest Secret: " << std::endl;
	c.setDarkestSecret( PhoneBook::_prompt(false) );
	this->size += (this->size < 8);
	++(this->it) %= 8;
}

std::string		PhoneBook::_prompt(bool d)
{
	std::stringstream	input_stream;
	std::string			input;
	std::string			parsed;

	do
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
			std::exit(0);
		else if (!input.empty())
		{
			input_stream.str(input);
			while ((input_stream >> input))
				parsed += input + ' ';
			parsed.pop_back();
			std::size_t p = parsed.find_first_not_of("0123456789", (parsed[0] == '+'));
			if (d && p != std::string::npos) parsed.clear();
		}
	} while (parsed.empty());
	
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
		std::string const fname = this->contact[i].getFirstName();
		std::string const lname = this->contact[i].getLastName();
		std::string const nname = this->contact[i].getNickName();
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << fname.length() > 10 ? fname.replace() << "|";
		std::cout << std::setw(10) << lname << "|";
		std::cout << std::setw(10) << nname << std::endl;
	}
}

void			PhoneBook::searchContact(void) const
{
	int			i;

	i = 0;
	do
		std::cout << "Enter index: ";
	while (!((std::cin >> i) && i > 0 && i <= this->size));
	PhoneBook::printContact(this->contact[i - 1]);
}