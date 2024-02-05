#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    Brain *brain;
public:
    Dog(void);
    Dog(Dog const & src);
    ~Dog(void);

    Dog & operator=(Dog const & src);

    void makeSound(void) const;
};