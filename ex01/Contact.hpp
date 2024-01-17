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
	
	void	getFirstName(void) const;
	void	getLastName(void) const;
	void	getPhoneNumber(void) const;
	void	getDarkestSecret(void) const;
};