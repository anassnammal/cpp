#pragma once

#include <iostream>

#define NB 7

class Zombie
{
	std::string	_name;
public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie();
	void	setName( std::string name );
	void	announce( void );

};

Zombie* zombieHorde( int N, std::string name );

