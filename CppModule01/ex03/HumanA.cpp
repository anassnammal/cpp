#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : _name(n), _weapon(w)
{
	
}

HumanA::~HumanA(void)
{

}

void	HumanA::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType();
	std::cout << std::endl;
}