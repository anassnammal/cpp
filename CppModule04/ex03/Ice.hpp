#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    Ice & operator=(Ice const & src);
public:
    Ice(void);
    Ice(Ice const & src);
    ~Ice(void);

	AMateria *clone() const;
    void use(ICharacter& target);
};

