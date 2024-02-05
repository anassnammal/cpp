#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{

public:
    Cure(void);
    Cure(Cure const & src);
    ~Cure(void);

    Cure & operator=(Cure const & src);

	AMateria *clone() const;
};

// std::ostream & operator<<(std::ostream & o, Cure const & src);

