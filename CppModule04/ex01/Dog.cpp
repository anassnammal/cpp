#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog: Default constructor called" << std::endl;
    return ;
}

Dog::Dog(Dog const & src) : Animal(src), brain(new Brain(*src.brain))
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    return ; 
}

Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
    return ;
}

Dog & Dog::operator=(Dog const & src)
{
    if (this != &src)
    {
        std::cout << "Dog: Copy assignment operator called" << std::endl;
        this->type = src.type;
		delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Dog making sound" << std::endl;
    return ;
}

// std::ostream & operator<<(std::ostream & o, Dog const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

