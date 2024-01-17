#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	Contact contact[8];
	int		it;
	std::string parseInput(void) const;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(void);
	void	searchContact(int id) const;
};