#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string &name, int grade) : name(name), grade(grade)
{
    
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
	: name(src.getName()), grade(src.getGrade())
{
    // std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    // std::cout << "Bureaucrat: Destructor called" << std::endl;
    return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    // if (this != &src)
    // {
    //     // std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    // }
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}

