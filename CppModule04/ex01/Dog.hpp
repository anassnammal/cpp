#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    Brain *brain;
public:
    Dog(void);
    Dog(Dog const & src);
    ~Dog(void);

    Dog & operator=(Dog const & src);

    void makeSound(void) const;
};