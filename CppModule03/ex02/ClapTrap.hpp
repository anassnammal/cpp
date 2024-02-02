#pragma once

#include <iostream>

class ClapTrap
{	
protected:
    std::string		name;
    unsigned int	hitPoints;
    unsigned int	energyPoints;
    unsigned int	attackDamage;

    ClapTrap(void);
public:
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &tmp);
    ClapTrap& operator=(ClapTrap const &tmp);
    ~ClapTrap(void);

    void    attack(std::string const &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};
