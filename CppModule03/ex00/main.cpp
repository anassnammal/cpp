#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap p1("player1");
	ClapTrap p2("player2");
	ClapTrap p3("player3");

	p1.attack("player2");
	p2.takeDamage(10);
	p2.attack("player1");
	p2.beRepaired(1);
	p2.attack("player3");
	p3.takeDamage(1);
	p1.attack("player2");
	p2.takeDamage(1);
	p2.attack("player1");

    return 0;
}
