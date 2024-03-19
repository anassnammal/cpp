#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	std::string const	&name;
	bool				isSigned;
	int const 			signGrade;
	int const 			execGrade;

    AForm(void);
    AForm & operator=(AForm const & src);

public:
    AForm(std::string const &name, int signGrade, int execGrade);
    AForm(AForm const & src);
    ~AForm(void);


	std::string const	&getName() const;
	bool				getSignState() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(Bureaucrat const &b);

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, AForm const & src);

