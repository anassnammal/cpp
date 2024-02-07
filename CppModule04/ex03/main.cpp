#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    return 0;
}
/*
MateriaSource: Default constructor called

AMateria: Parametrized constructor called
Ice: Default constructor called

AMateria: Parametrized constructor called
Cure: Default constructor called

Character: Parametrized constructor called

Character: Parametrized constructor called

Character: Destructor called
Character: Destructor called
MateriaSource: Destructor called
Ice: Destructor called
AMateria: Destructor called
Cure: Destructor called
AMateria: Destructor called
*/