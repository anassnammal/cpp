#pragma once

#include "Contact.hpp"
#include <string>

class PhoneBook {
	Contact		contact[8];
	unsigned int	size;
	unsigned int	it;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(std::string attr[5]);
	const Contact	*searchContact(unsigned int id) const;
};