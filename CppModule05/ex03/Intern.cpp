#include "Intern.hpp"

Intern::Intern(void)
{
    // std::cout << "Intern: Default constructor called" << std::endl;
    return ;
}

Intern::Intern(Intern const & src)
{
    // std::cout << "Intern: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Intern::~Intern(void)
{
    // std::cout << "Intern: Destructor called" << std::endl;
    return ;
}

Intern & Intern::operator=(Intern const & src)
{
    if (this != &src)
    {
        // std::cout << "Intern: Copy assignment operator called" << std::endl;
    }
    return *this;
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    int i = (name == "shrubbery creation") * 1 + (name == "robotomy request") * 2 + (name == "presidential pardon") * 3;
    AForm   *ptr = NULL;
    switch (i)
    {
    case 1:
        ptr = new ShrubberyCreationForm(target);
        break;
    case 2:
        ptr = new RobotomyRequestForm(target);
        break;
    case 3:
        ptr = new PresidentialPardonForm(target);
        break;
    
    default:
        throw FormNotValid();
        break;
    }
    return ptr;
}

const char *Intern::FormNotValid::what() const throw()
{
    return "Requested form name doesn't exis!";
}

// std::ostream & operator<<(std::ostream & o, Intern const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

