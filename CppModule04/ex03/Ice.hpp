#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

public:
    Ice(void);
    Ice(Ice const & src);
    ~Ice(void);

    Ice & operator=(Ice const & src);
	AMateria *clone() const;
};

// std::ostream & operator<<(std::ostream & o, Ice const & src);

