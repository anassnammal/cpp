#include "HumanB.hpp"

HumanB::HumanB(std::string n) : _name(n)
{
	
}

HumanB::~HumanB(void)
{

}

void	HumanB::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->_weapon = &w;
}