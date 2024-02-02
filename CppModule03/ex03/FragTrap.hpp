#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    FragTrap(void);

public:
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);
    ~FragTrap(void);

    FragTrap & operator=(FragTrap const & src);

	void highFivesGuys(void);
};
