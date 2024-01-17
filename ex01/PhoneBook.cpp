#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void	PhoneBook::addContact(void)
{
	this->contact[this->it].setFirstName();
	this->contact[this->it].setLastName();
	this->contact[this->it].setPhoneNumber();
	this->contact[this->it].setDarkestSecret();
	++(this->it) %= 8;
}

void	PhoneBook::searchContact(void) const
{
	int	id;

	std::cout << "enter an index: ";
	while (!(std::cin >> id) || id > 7 || id < 0)
		std::cout << "enter a valid index: ";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << id << '|';
	this->contact[id].getFirstName();
	this->contact[id].getLastName();
	this->contact[id].getPhoneNumber();
	this->contact[id].getDarkestSecret();
	std::cout << std::endl;
}

