#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap p1("player1");
	ScavTrap p2("player2");
	ScavTrap p3("player3");

	p1.attack("player2");
	p2.takeDamage(20);
	p2.attack("player1");
	p2.beRepaired(10);
	p2.attack("player3");
	p3.takeDamage(20);
	p1.attack("player2");
	p2.takeDamage(20);
	p2.attack("player1");

	p2.guardGate();
	
    return 0;
}
