#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) 
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
    // std::cout << "Form: Default constructor called" << std::endl;
    return ;
}

Form::Form(Form const & src)
	: name(src.getName()), isSigned(src.getSignState()),
		signGrade(src.getSignGrade()), execGrade(src.getExecGrade())
{
    // std::cout << "Form: Copy constructor called" << std::endl;
    return ;
}

Form::~Form(void)
{
    // std::cout << "Form: Destructor called" << std::endl;
    return ;
}

std::string const	&Form::getName() const
{
	return (name);
}

bool				Form::getSignState() const
{
	return (isSigned);
}

int const			Form::getSignGrade() const
{
	return (signGrade);
}

int const			Form::getExecGrade() const
{
	return (execGrade);
}

void				Form::beSigned(Bureaucrat const &b)
{
	if (signGrade < b.getGrade())
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream & operator<<(std::ostream & o, Form const & src)
{
	std::string	tmp;
	if (src.getSignState())
		tmp = " signed, ";
	else
		tmp = " not signed yet, ";
    o << "Form " << src.getName() << tmp;
	o << "its grade required to sign it is : " << src.getSignGrade();
	o << "its grade required to execute it is : " << src.getExecGrade();
    return o;
}

