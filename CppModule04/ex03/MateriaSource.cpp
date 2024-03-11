#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : count(0)
{
    std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : count(0)
{
    std::cout << "MateriaSource: Copy constructor called" << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource: Destructor called" << std::endl;
    for (int i = 0; i < this->count; i++)
        delete this->materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this != &src)
    {
        std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
        for (int i = 0; i < this->count; i++)
            delete this->materia[i];
        this->count = src.count;
        for (int i = 0; i < this->count; i++)
            this->materia[i] = src.materia[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (this->count < 4 && m)
    {
        this->materia[this->count] = m;
        this->count++;
    }
	else
		delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->count; i++)
    {
        std::string const &tmp = this->materia[i]->getType();
        if ( tmp == type)
            return (this->materia[i]->clone());
    }
    return (0);
}