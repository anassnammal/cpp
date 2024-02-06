#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    Cure & operator=(Cure const & src);
public:
    Cure(void);
    Cure(Cure const & src);
    ~Cure(void);

	AMateria *clone() const;
    void use(ICharacter& target);
};


