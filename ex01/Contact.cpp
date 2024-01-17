#include "Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{
	
}

std::string	Contact::readInput(int (*format)(int))
{
	bool		notValid;
	std::string	input;

	notValid = true;
	while (notValid)
	{
		notValid = false;
		std::cin >> input;
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
		{
			if (!format(*it))
				notValid = true;
		}
		std::cout << "\r";
	}
	return (input);
}

void Contact::setFirstName(void)
{
	std::cout << "Enter the first name :";
	this->firstName = this->readInput(std::isalpha);
}

void Contact::setLastName(void)
{
	std::cout << "Enter the last name :";
	this->lastName = this->readInput(std::isalpha);
}

void Contact::setPhoneNumber(void)
{
	std::cout << "Enter the phone number :";
	this->phoneNumber = this->readInput(std::isdigit);
}

void Contact::setDarkestSecret(void)
{
	std::cout << "Enter the darkest secret :";
	this->darkestSecret = this->readInput(std::isalpha);
}

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
