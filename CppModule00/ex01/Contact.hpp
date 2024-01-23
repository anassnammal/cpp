#pragma once

#include <string>
#include <iostream>
#include <iomanip>

#define BG_COLOR "\033[1;47m"
#define BG_NOCLR "\033[0m"

class Contact {
	std::string	firstName;
	std::string	lastName;
	std::string nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	~Contact();

	void		setFirstName(std::string input);
	void		setLastName(std::string input);
	void		setNickName(std::string input);
	void		setPhoneNumber(std::string input);
	void		setDarkestSecret(std::string input);

	void		printContact(void) const;
};