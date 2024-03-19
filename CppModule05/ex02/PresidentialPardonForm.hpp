#pragma once

#include <iostream>

class PresidentialPardonForm
{

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
};

// std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src);

