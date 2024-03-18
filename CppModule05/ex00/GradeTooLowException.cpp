#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(void)
{
    // std::cout << "GradeTooLowException: Default constructor called" << std::endl;
    return ;
}

GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
    // std::cout << "GradeTooLowException: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

GradeTooLowException::~GradeTooLowException(void)
{
    // std::cout << "GradeTooLowException: Destructor called" << std::endl;
    return ;
}

GradeTooLowException & GradeTooLowException::operator=(GradeTooLowException const & src)
{
    if (this != &src)
    {
        // std::cout << "GradeTooLowException: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, GradeTooLowException const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

