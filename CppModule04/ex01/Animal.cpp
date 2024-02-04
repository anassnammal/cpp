#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal: Default constructor called" << std::endl;
    return ;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal: Parametric constructor called" << std::endl;
    return ;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal: Destructor called" << std::endl;
    return ;
}

Animal & Animal::operator=(Animal const & src)
{
    if (this != &src)
    {
        std::cout << "Animal: Copy assignment operator called" << std::endl;
        this->type = src.type;
    }
    return *this;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal: makeSound called" << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
    return this->type;
}

// std::ostream & operator<<(std::ostream & o, Animal const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

