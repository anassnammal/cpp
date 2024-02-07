#include "Character.hpp"

Character::Character(std::string const & name) : name(name), count(0)
{
    std::cout << "Character: Parametrized constructor called" << std::endl;
    return ;
}

Character::Character(Character const & src)
{
    std::cout << "Character: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Character::~Character(void)
{
    std::cout << "Character: Destructor called" << std::endl;
    for (int i = 0; i < this->count; i++)
        delete this->materia[i];
    return ;
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        std::cout << "Character: Copy assignment operator called" << std::endl;
        this->name = src.name;
        for (int i = 0; i < this->count; i++)
            delete this->materia[i];
        this->count = src.count;
        for (int i = 0; i < this->count; i++)
            this->materia[i] = src.materia[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (this->count < 4 && m)
    {
        this->materia[this->count] = m;
        this->count++;
    }
	else
		delete m;
    return ;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->count)
    {
		delete this->materia[idx];
        for (int i = idx; i < this->count - 1; i++)
            this->materia[i] = this->materia[i + 1];
        this->count--;
    }
    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < this->count)
        this->materia[idx]->use(target);
    return ;
}

