#include "AForm.hpp"

AForm::AForm(std::string const &name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) 
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
    // std::cout << "AForm: Default constructor called" << std::endl;
    return ;
}

AForm::AForm(AForm const & src)
	: name(src.getName()), isSigned(src.getSignState()),
		signGrade(src.getSignGrade()), execGrade(src.getExecGrade())
{
    // std::cout << "AForm: Copy constructor called" << std::endl;
    return ;
}

AForm::~AForm(void)
{
    // std::cout << "AForm: Destructor called" << std::endl;
    return ;
}

std::string const	&AForm::getName() const
{
	return (name);
}

bool				AForm::getSignState() const
{
	return (isSigned);
}

int					AForm::getSignGrade() const
{
	return (signGrade);
}

int					AForm::getExecGrade() const
{
	return (execGrade);
}

void				AForm::beSigned(Bureaucrat const &b)
{
	if (isSigned)
		throw AForm::FormAlreadySignedException();
	if (signGrade < b.getGrade())
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

std::ostream & operator<<(std::ostream & o, AForm const & src)
{
	std::string	tmp;
	if (src.getSignState())
		tmp = "signed";
	else
		tmp = "not signed yet";
    o << "Form name: " << src.getName() << std::endl;
	o << "Form state: " << tmp << std::endl;
	o << "Sign grade: " << src.getSignGrade() << std::endl;
	o << "Execution grade: " << src.getExecGrade();
    return o;
}

