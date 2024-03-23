#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

class ScalarConverter
{
    enum type {
        T_CHAR,
        T_VALID,
        T_SPECIAL,
        T_INVALID
    };

    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter(void);

    ScalarConverter & operator=(ScalarConverter const & src);

public:

    static  type    identifyInput(std::string& input);
    static  void    convert(std::string s);

};

// std::ostream & operator<<(std::ostream & o, ScalarConverter const & src);

