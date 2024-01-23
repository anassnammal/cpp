#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	std::string	const	_name;
	Weapon				*_weapon;

public:
	HumanB(std::string n);
	~HumanB(void);

	void		setWeapon(Weapon &w);
	void		attack(void) const;
};