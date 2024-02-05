#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string const &type;
    AMateria(void);
public:
	AMateria(std::string const &type);
    AMateria(AMateria const & src);
    ~AMateria(void);

    AMateria & operator=(AMateria const & src);

	std::string const & getType(void) const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target);
};
 
