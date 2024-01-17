#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

std::string PhoneBook::parseInput(void) const
{

}

void	PhoneBook::addContact(void)
{
	int	i = this->it;
	std::string	(*rdInp)(void);
	
	rdInp = this->parseInput;
	this->contact[i].setFirstName();
	this->contact[i].setLastName();
	this->contact[i].setPhoneNumber();
	this->contact[i].setDarkestSecret();
	++(this->it) %= 8;
}

void	PhoneBook::searchContact(int id) const
{
	std::cout << "enter an index: ";
	while (!(std::cin >> id) || id > 7 || id < 0)
		std::cout << "enter a valid index: ";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->contact[id].getFirstName() << '|';
	std::cout << this->contact[id].getLastName() << '|';
	std::cout << this->contact[id].getPhoneNumber() << '|';
	std::cout << this->contact[id].getDarkestSecret() << '|';
	std::cout << std::endl;
}

