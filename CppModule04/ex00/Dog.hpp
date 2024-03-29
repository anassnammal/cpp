#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(Dog const & src);
    ~Dog(void);

    Dog & operator=(Dog const & src);

    void makeSound(void) const;
};