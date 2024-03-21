#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    RobotomyRequestForm(void);
    RobotomyRequestForm &operator=(RobotomyRequestForm const & src);

public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    ~RobotomyRequestForm(void);

    
    virtual void        execute(Bureaucrat const & executor) const;
};

// std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src);