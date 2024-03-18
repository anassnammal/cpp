#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(void)
{
    // std::cout << "GradeTooHighException: Default constructor called" << std::endl;
    return ;
}

GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
    // std::cout << "GradeTooHighException: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

GradeTooHighException::~GradeTooHighException(void)
{
    // std::cout << "GradeTooHighException: Destructor called" << std::endl;
    return ;
}

GradeTooHighException & GradeTooHighException::operator=(GradeTooHighException const & src)
{
    if (this != &src)
    {
        // std::cout << "GradeTooHighException: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, GradeTooHighException const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

