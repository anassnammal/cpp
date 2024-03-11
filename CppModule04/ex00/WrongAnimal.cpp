#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
    std::cout << "WrongAnimal: Parametric constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
    return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    if (this != &src)
    {
        std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
        this->type = src.type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal making sound" << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

// std::ostream & operator<<(std::ostream & o, Animal const & src)
// {
//     o << "ostream operator called";
//     return o;
// }



