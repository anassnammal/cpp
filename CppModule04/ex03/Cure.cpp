#include "Cure.hpp"

Cure::Cure(void)
{
    // std::cout << "Cure: Default constructor called" << std::endl;
    return ;
}

Cure::Cure(Cure const & src)
{
    // std::cout << "Cure: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cure::~Cure(void)
{
    // std::cout << "Cure: Destructor called" << std::endl;
    return ;
}

Cure & Cure::operator=(Cure const & src)
{
    if (this != &src)
    {
        // std::cout << "Cure: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, Cure const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

