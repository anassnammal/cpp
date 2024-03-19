#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	std::string const	&name;
	bool				isSigned;
	int const 			signGrade;
	int const 			execGrade;

    Form(void);
    Form & operator=(Form const & src);

public:
    Form(std::string const &name, int signGrade, int execGrade);
    Form(Form const & src);
    ~Form(void);


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

std::ostream & operator<<(std::ostream & o, Form const & src);

