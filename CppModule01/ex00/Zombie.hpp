#pragma once

#include <iostream>

class Zombie
{
	std::string	_name;
public:

	Zombie(std::string name);
	~Zombie();

	void	announce( void );

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

