#pragma once

#include <iostream>

class Brain
{
    std::string ideas[100];
public:
    Brain(void);
    Brain(Brain const & src);
    ~Brain(void);

    Brain & operator=(Brain const & src);
};

// std::ostream & operator<<(std::ostream & o, Brain const & src);

