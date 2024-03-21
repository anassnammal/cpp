#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	std::string const	name;
	int					grade;
	
    Bureaucrat(void);
    Bureaucrat & operator=(Bureaucrat const & src);

public:
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat(void);


	std::string const	&getName() const;
	int					getGrade() const;
	void				gradeUp();
	void				gradeDown();

	void				signForm(AForm &form);
	void				executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

