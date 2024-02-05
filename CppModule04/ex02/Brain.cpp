#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain: Default constructor called" << std::endl;
    return ;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain(void)
{
    std::cout << "Brain: Destructor called" << std::endl;
    return ;
}

Brain & Brain::operator=(Brain const & src)
{
    if (this != &src)
    {
        std::cout << "Brain: Copy assignment operator called" << std::endl;
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, Brain const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

