#include "Contact.hpp"

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{

}

void		Contact::setFirstName(std::string input)
{
	this->firstName = input;
}

void		Contact::setLastName(std::string input)
{
	this->lastName = input;
}

void		Contact::setNickName(std::string input)
{
	this->nickName = input;
}

void		Contact::setPhoneNumber(std::string input)
{
	this->phoneNumber = input;
}

void		Contact::setDarkestSecret(std::string input)
{
	this->darkestSecret = input;
}

void	Contact::printContact(void) const
{
	std::cout << std::setw(10);
	std::cout << this->firstName << '|';
	std::cout << this->lastName << '|';
	std::cout << this->nickName << '|';
	std::cout << this->phoneNumber << '|';
	std::cout << this->darkestSecret << '|';
}

