#pragma once

#include <iostream>
#include <string>

class Contact {
	std::string	firstName;
	std::string	lastName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	~Contact();

	void		setFirstName(std::string input);
	void		setLastName(std::string input);
	void		setPhoneNumber(std::string input);
	void		setDarkestSecret(std::string input);
	
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};