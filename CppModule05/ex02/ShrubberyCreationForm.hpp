#pragma once

#include <iostream>

class ShrubberyCreationForm
{

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
};

// std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src);

