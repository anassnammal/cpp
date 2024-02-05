#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    Brain *brain;
public:
    Cat(void);
    Cat(Cat const & src);
    ~Cat(void);

    Cat & operator=(Cat const & src);

    void makeSound(void) const;
};
