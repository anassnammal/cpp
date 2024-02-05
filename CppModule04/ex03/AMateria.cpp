#include "AMateria.hpp"

AMateria::AMateria(void)
{
    // std::cout << "AMateria: Default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(AMateria const & src)
{
    // std::cout << "AMateria: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

AMateria::~AMateria(void)
{
    // std::cout << "AMateria: Destructor called" << std::endl;
    return ;
}

AMateria & AMateria::operator=(AMateria const & src)
{
    if (this != &src)
    {
        // std::cout << "AMateria: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, AMateria const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

