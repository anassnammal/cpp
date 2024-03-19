#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
    // std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
    // std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    // std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    if (this != &src)
    {
        // std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

