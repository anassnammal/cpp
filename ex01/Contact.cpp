#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

std::string	Contact::readInput(int (*format)(int))
{
	std::string	input;
	bool		valid;

	valid = false;
	while (!valid)
	{
		valid = true;
		std::cin >> input;
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
		{
			if (format && !format(*it) && !std::isspace(*it))
				valid = false;
		}
	}
	if (input.length() > 10)
		input = input.substr(0, 9) + '.';
	return (input);
}

void		Contact::setFirstName(void)
{
	std::cout << "Enter the first name :";
	this->firstName = this->readInput(NULL);
}

void		Contact::setLastName(void)
{
	std::cout << "Enter the last name :";
	this->lastName = this->readInput(NULL);
}

void		Contact::setPhoneNumber(void)
{
	std::cout << "Enter the phone number :";
	this->phoneNumber = this->readInput(std::isdigit);
}

void		Contact::setDarkestSecret(void)
{
	std::cout << "Enter the darkest secret :";
	this->darkestSecret = this->readInput(NULL);
}

void		Contact::getFirstName(void) const
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->firstName;
}

void		Contact::getLastName(void) const
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->lastName;
}

void		Contact::getPhoneNumber(void) const
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->phoneNumber;
}

void		Contact::getDarkestSecret(void) const
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->darkestSecret;
}
