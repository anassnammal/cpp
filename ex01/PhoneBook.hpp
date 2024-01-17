#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	Contact contact[8];
	int		it;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(void);
	void	searchContact(void) const;
};