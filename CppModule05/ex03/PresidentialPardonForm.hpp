#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    PresidentialPardonForm(void);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    ~PresidentialPardonForm(void);


    virtual void        execute(Bureaucrat const & executor) const;
};

// std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src);

