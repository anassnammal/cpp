#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    Brain *brain;
public:
    Cat(void);
    Cat(Cat const & src);
    ~Cat(void);

    Cat & operator=(Cat const & src);

    void makeSound(void) const;
};
