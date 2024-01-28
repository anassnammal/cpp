#pragma once

#include <string>
#include <iostream>
#include <iomanip>


class Contact {
	std::string	firstName;
	std::string	lastName;
	std::string nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	~Contact();

	void				setFirstName(std::string input);
	void				setLastName(std::string input);
	void				setNickName(std::string input);
	void				setPhoneNumber(std::string input);
	void				setDarkestSecret(std::string input);

	std::string const &	getFirstName(void) const;
	std::string const &	getLastName(void) const;
	std::string const &	getNickName(void) const;
	std::string const &	getPhoneNumber(void) const;
	std::string const &	getDarkestSecret(void) const;
};