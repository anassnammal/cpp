#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice: Default constructor called" << std::endl;
    return ;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
    std::cout << "Ice: Copy constructor called" << std::endl;
    return ;
}

Ice::~Ice(void)
{
    std::cout << "Ice: Destructor called" << std::endl;
    return ;
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}

