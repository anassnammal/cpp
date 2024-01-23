#include "Zombie.hpp"

int main(void)
{
	Zombie *z_heap = newZombie("heap");
	randomChump("stack");

	z_heap->announce();
	delete z_heap;
	return 0;
}
