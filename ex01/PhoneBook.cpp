#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->size = 0;
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void	PhoneBook::addContact(std::string attr[5])
{
	Contact	c = this->contact[this->it];
	c.setFirstName(attr[0]);
	c.setLastName(attr[1]);
	c.setNickName(attr[2]);
	c.setPhoneNumber(attr[3]);
	c.setDarkestSecret(attr[4]);
	this->size += (this->size < 8);
	++(this->it) %= 8;
}

const Contact	*PhoneBook::searchContact(int id) const
{
	if (id >= this->size)
		return (NULL);
	return (&this->contact[id]);
}

