#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal: Default constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(std::string type): type(type)
{
    std::cout << "AAnimal: Parametric constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "AAnimal: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal: Destructor called" << std::endl;
    return ;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    if (this != &src)
    {
        std::cout << "AAnimal: Copy assignment operator called" << std::endl;
        this->type = src.type;
    }
    return *this;
}

std::string AAnimal::getType(void) const
{
    return this->type;
}
