#pragma once

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(std::string type);
    Animal(Animal const & src);
    virtual ~Animal(void);

    Animal & operator=(Animal const & src);

    virtual void makeSound(void) const;
    std::string getType(void) const;
};

// std::ostream & operator<<(std::ostream & o, Animal const & src);

