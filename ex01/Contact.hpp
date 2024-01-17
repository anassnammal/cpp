#pragma once

#include <iostream>
#include <string>

class Contact {
	std::string	firstName;
	std::string	lastName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::string	readInput(int (*format)(int));
public:
	Contact();
	~Contact();

	void		setFirstName(void);
	void		setLastName(void);
	void		setPhoneNumber(void);
	void		setDarkestSecret(void);
	
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};