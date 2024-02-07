#pragma once

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const & src);
    ~WrongAnimal(void);

    WrongAnimal & operator=(WrongAnimal const & src);

    void makeSound(void) const;
    std::string getType(void) const;
};
