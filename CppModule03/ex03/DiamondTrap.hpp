#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	std::string	name;
    DiamondTrap(void);
public:
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const & src);
    ~DiamondTrap(void);

    DiamondTrap &	operator=(DiamondTrap const & src);

	void			attack(std::string const & target);
	void			whoAmI(void);
};
