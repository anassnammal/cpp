#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45)
{
    // std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
    // std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    // std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
    return ;
}

void            RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static bool execFormCount;

    checkRequirement(executor);
    std::cout << "Drl..drl...drrrrrrrrrrrrrrrr!" << std::endl;
    if (!execFormCount)
        std::cout << this->getName() << " has been robotomized successfull" << std::endl;
    else
        std::cout << this->getName() << " hasn't been robotomized" << std::endl;
    execFormCount ^= true;
}

// std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

