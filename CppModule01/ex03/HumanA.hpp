#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	std::string	const	_name;
	Weapon				&_weapon;

public:
	HumanA(std::string n, Weapon &w);
	~HumanA(void);

	void		attack(void) const;
};

