#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
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

std::string const	&Bureaucrat::getName() const
{
    return name;
}

int					Bureaucrat::getGrade() const
{
    return grade;
}

void				Bureaucrat::gradeUp()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
    return ;
}

void				Bureaucrat::gradeDown()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
    return ;
}

void                Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    return ;
}

void                Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}

