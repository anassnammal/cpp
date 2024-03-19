#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
    // std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
    // std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    // std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
    return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    if (this != &src)
    {
        // std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

