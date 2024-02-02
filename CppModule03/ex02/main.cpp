#include "FragTrap.hpp"

int main(void)
{
	FragTrap p1("player1");
	FragTrap p2("player2");
	FragTrap p3("player3");

	p1.attack("player2");
	p2.takeDamage(30);
	p2.attack("player1");
	p2.beRepaired(15);
	p2.attack("player3");
	p3.takeDamage(30);
	p1.attack("player2");
	p2.takeDamage(30);
	p2.attack("player1");

	p2.highFivesGuys();
    return 0;
}
