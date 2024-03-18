#pragma once

#include <iostream>

class GradeTooHighException : public std::exception
{

public:
	virtual const char *what() const throw();

    GradeTooHighException & operator=(GradeTooHighException const & src);
};

// std::ostream & operator<<(std::ostream & o, GradeTooHighException const & src);

