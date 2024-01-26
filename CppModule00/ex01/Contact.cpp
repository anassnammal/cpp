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

std::string const &		Contact::getFirstName(void) const
{
	return (this->firstName);
}

std::string const &		Contact::getLastName(void) const
{
	return (this->lastName);
}

std::string const &		Contact::getNickName(void) const
{
	return (this->nickName);
}

std::string const &		Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

std::string const &		Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
