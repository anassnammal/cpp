#pragma once

#include <iostream>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal(AAnimal const & src);
    virtual ~AAnimal(void);

    AAnimal & operator=(AAnimal const & src);

    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};
