#include "Ice.hpp"

Ice::Ice(void)
{
    // std::cout << "Ice: Default constructor called" << std::endl;
    return ;
}

Ice::Ice(Ice const & src)
{
    // std::cout << "Ice: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Ice::~Ice(void)
{
    // std::cout << "Ice: Destructor called" << std::endl;
    return ;
}

Ice & Ice::operator=(Ice const & src)
{
    if (this != &src)
    {
        // std::cout << "Ice: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, Ice const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

