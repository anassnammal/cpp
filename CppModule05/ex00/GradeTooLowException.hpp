#pragma once

#include <iostream>

class GradeTooLowException
{

public:
    GradeTooLowException(void);
    GradeTooLowException(GradeTooLowException const & src);
    ~GradeTooLowException(void);

    GradeTooLowException & operator=(GradeTooLowException const & src);
};

// std::ostream & operator<<(std::ostream & o, GradeTooLowException const & src);

