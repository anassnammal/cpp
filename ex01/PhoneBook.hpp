#pragma once

#include "Contact.hpp"
#include <string>

class PhoneBook {
	Contact contact[8];
	int		size;
	int		it;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(std::string attr[5]);
	const Contact	*searchContact(int id) const;
};