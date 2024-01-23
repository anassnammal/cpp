#pragma once

#include <iostream>

class Weapon
{
	std::string _type;

public:
	Weapon(void);
	Weapon(std::string t);
	~Weapon(void);

	std::string const	&getType(void) const;
	void				setType(std::string type);
};
