#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    std::string name;
    AMateria *materia[4];
    int count;
    
    Character(void);
public:
    Character(std::string const & name);
    Character(Character const & src);
    ~Character(void);

    Character & operator=(Character const & src);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

