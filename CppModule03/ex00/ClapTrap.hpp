#pragma once

#include <iostream>

class ClapTrap
{
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
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
