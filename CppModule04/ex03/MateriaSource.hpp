#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    AMateria *materia[4];
    int count;

public:
    MateriaSource(void);
    MateriaSource(MateriaSource const & src);
    ~MateriaSource(void);

    MateriaSource & operator=(MateriaSource const & src);

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const & type);
};
