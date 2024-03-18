#pragma once

#include <iostream>

class Bureaucrat
{
	std::string const	name;
	int					grade;
	
    Bureaucrat(void);

public:
    Bureaucrat(std::string &name, int grade);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat(void);

    Bureaucrat & operator=(Bureaucrat const & src);

	std::string const	&getName() const;
	int					getGrade() const;
	void				gradeUp();
	void				gradeDown();
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

