#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>

class PhoneBook {
	Contact	contact[8];
	int		size;
	int		it;

	static std::string	_prompt(bool d);
	static void			printContact(Contact const & c);

public:
	PhoneBook(void);
	~PhoneBook(void);
	
	void 	listContact(void);
	void	addContact(void);
	void	searchContact(void) const;

};