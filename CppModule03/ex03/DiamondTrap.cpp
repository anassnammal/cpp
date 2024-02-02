#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    // std::cout << "DiamondTrap default constructor called" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    // std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	hitPoints = this->FragTrap::hitPoints;
	energyPoints = this->ScavTrap::energyPoints;
	attackDamage = this->FragTrap::attackDamage;
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
    this->name = ClapTrap::name;
    *this = src;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    // std::cout << "DiamondTrap destructor called" << std::endl;
    return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
    if (this != &src)
    {
        // std::cout << "DiamondTrap assignation operator called" << std::endl;
    }
    return *this;
}

void DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is: " << this->DiamondTrap::name << std::endl;
	std::cout << "ClapTrap name is: " << this->ClapTrap::name << std::endl;
}
