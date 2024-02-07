#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat: Default constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat: Destructor called" << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    if (this != &src)
    {
        std::cout << "WrongCat: Copy assignment operator called" << std::endl;
        this->type = src.type;
    }
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat making sound" << std::endl;
    return ;
}

// std::ostream & operator<<(std::ostream & o, Cat const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

