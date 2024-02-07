#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    AMateria(void);
    AMateria & operator=(AMateria const & src);
protected:
	std::string const type;
public:
	AMateria(std::string const &type);
    AMateria(AMateria const & src);
    virtual ~AMateria(void);

	std::string const & getType(void) const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target);
};
 
