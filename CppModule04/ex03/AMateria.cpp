#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria: Parametrized constructor called" << std::endl;
    return ;
}

AMateria::AMateria(AMateria const & src) : type(src.type)
{
    std::cout << "AMateria: Copy constructor called" << std::endl;
    return ;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria: Destructor called" << std::endl;
    return ;
}

std::string const & AMateria::getType(void) const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses a materia on " << target.getName() << " *" << std::endl;
    return ;
}
