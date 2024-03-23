#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer
{

    Serializer(void);
    Serializer(Serializer const & src);
    ~Serializer(void);

    Serializer & operator=(Serializer const & src);

public:
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
};

// std::ostream & operator<<(std::ostream & o, Serializer const & src);

