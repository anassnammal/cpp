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
	while (!(std::cin >> id) || id > 7)
		std::cout << "\r";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << id << '|';
	std::cout << this->contact[id].getFirstName() << '|';
	std::cout << this->contact[id].getLastName() << '|';
	std::cout << this->contact[id].getPhoneNumber() << '|';
	std::cout << this->contact[id].getDarkestSecret() << '|';
}

