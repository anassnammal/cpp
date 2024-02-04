#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat: Default constructor called" << std::endl;
    brain = new Brain();
    return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
    return ;
}

Cat & Cat::operator=(Cat const & src)
{
    if (this != &src)
    {
        std::cout << "Cat: Copy assignment operator called" << std::endl;
        this->type = src.type;
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat making sound" << std::endl;
    return ;
}

// std::ostream & operator<<(std::ostream & o, Cat const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

