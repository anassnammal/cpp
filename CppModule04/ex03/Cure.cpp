#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure: Default constructor called" << std::endl;
    return ;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
    std::cout << "Cure: Copy constructor called" << std::endl;
    return ;
}

Cure::~Cure(void)
{
    std::cout << "Cure: Destructor called" << std::endl;
    return ;
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}