#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 25, 5)
{
    // std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
    // std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    // std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
    return ;
}

void            PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    checkRequirement(executor);
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

