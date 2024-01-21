#include "PhoneBook.hpp"
#include <iostream>
PhoneBook::PhoneBook(void)
{
	this->size = 0;
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void	PhoneBook::addContact(std::string input[5])
{
	Contact	&c = this->contact[this->it];
	c.setFirstName(input[0]);
	c.setLastName(input[1]);
	c.setNickName(input[2]);
	c.setPhoneNumber(input[3]);
	c.setDarkestSecret(input[4]);
	this->size += (this->size < 8);
	++(this->it) %= 8;
}

const Contact	*PhoneBook::searchContact(int id) const
{
	if (id >= this->size)
		return (NULL);
	return (&this->contact[id]);
}

