#pragma once

#include <iostream>

#define NPRINT  "not displayable"
#define IMPOSS  "impossible"
#define MINF    "-inf"
#define PINF    "+inf"
#define NAN     "nan"

class ScalarConverter
{
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter(void);

    ScalarConverter & operator=(ScalarConverter const & src);

public:
    static  void    convert(std::string const s);
};

// std::ostream & operator<<(std::ostream & o, ScalarConverter const & src);

