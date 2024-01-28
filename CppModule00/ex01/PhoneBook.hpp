#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>
// #include <limits>

class PhoneBook {
	Contact	contact[8];
	int		size;
	int		it;

	void 	listContact(void) const;
	void	addContact(void);
	void	searchContact(void) const;

	static std::string	_prompt(bool d, std::string msg);
	static void			printContact(Contact const & c);

public:
	PhoneBook(void);	
	~PhoneBook(void);
	
	void	launch(void);
};


#define BG_COLOR "\033[1;47m"
#define BG_NOCLR "\033[0m"

#define IN "Index"
#define FN "First Name"
#define LN "Last Name"
#define NN "Nick Name"
#define PN "Phone Number"
#define DS "Darkest Secret"
#define ENTER(m) BG_COLOR"Enter contact "m": "BG_NOCLR" "
#define OUTPUT(m) BG_COLOR m":\t"BG_NOCLR

#define TURNCATE_IF(s) ((s.length() > 10) ? (s.replace(9, s.npos, ".")) : (s)) 
