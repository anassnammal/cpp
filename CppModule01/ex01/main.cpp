#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(NB, "z_nation");
	for (size_t i = 0; i < NB; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
