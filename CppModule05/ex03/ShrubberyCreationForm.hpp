#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm  : public AForm
{
    ShrubberyCreationForm(void);
    ShrubberyCreationForm   &operator=(ShrubberyCreationForm const & src);

public:
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ~ShrubberyCreationForm(void);

    virtual void            execute(Bureaucrat const & executor) const;
};

// std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src);

