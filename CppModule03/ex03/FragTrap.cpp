#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	std::cout << "FragTrap copy assignment called" << std::endl;
    if (this != &src)
    {
        name = src.name;
		hitPoints = src.hitPoints;
		attackDamage = src.attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "high fives to Everyone from FragTrap " << name << std::endl;
}