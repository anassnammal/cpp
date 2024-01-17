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

}

void		Contact::setFirstName(std::string input)
{
	this->firstName = input;
	// input.length() > 10 ? input.substr(0, 9) + '.' : input;
}

void		Contact::setLastName(std::string input)
{
	this->lastName = input;
}

void		Contact::setPhoneNumber(std::string input)
{
	this->phoneNumber = input;
}

void		Contact::setDarkestSecret(std::string input)
{
	this->darkestSecret = input;
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