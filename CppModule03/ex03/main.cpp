#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap p1("player1");
	DiamondTrap p2("player2");
	DiamondTrap p3("player3");

	p1.attack("player2");
	p2.takeDamage(20);
	p2.attack("player1");
	p2.beRepaired(10);
	p2.attack("player3");
	p3.takeDamage(20);
	p1.attack("player2");

	p1.whoAmI();
	p2.whoAmI();
	p3.whoAmI();
	
    return 0;
}
