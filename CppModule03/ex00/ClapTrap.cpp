#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    // useless constructor
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &tmp)
{
    std::cout << "ClapTrap " << tmp.name << " is copied" << std::endl;
    *this = tmp;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &tmp)
{
    std::cout << "ClapTrap " << tmp.name << " is assigned" << std::endl;
    this->name = tmp.name;
    this->hitPoints = tmp.hitPoints;
    this->energyPoints = tmp.energyPoints;
    this->attackDamage = tmp.attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->name << " is destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy points to attack " << target << "!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hitPoints -= amount;
    }
    else
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints < 10 && this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
        this->hitPoints += amount;
        this->hitPoints %= 10;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << " is already at full health!" << std::endl;
}

