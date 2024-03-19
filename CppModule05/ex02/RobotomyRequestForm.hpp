#pragma once

#include <iostream>

class RobotomyRequestForm
{

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
};

// std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src);

