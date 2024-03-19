#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
    // std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
    // std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    // std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
    return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    if (this != &src)
    {
        // std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

