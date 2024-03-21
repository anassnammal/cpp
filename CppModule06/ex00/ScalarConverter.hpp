#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter(void);

    ScalarConverter & operator=(ScalarConverter const & src);

public:
    static  void    convert(std::string const s);

    class OverFlowedInput : std::exception
    {
        public:
            virtual const char *what() const throw();

    };
};

// std::ostream & operator<<(std::ostream & o, ScalarConverter const & src);

