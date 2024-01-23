#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];

	for (size_t i = 0; i < NB; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}