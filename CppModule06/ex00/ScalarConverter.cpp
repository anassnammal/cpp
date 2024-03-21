#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

void ScalarConverter::convert(std::string const s)
{
    try {
        if (s.find(NAN) != std::string::npos || s.find(PINF) != std::string::npos || s.find(MINF) != std::string::npos)
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        } else {
            int i = atoi(s.c_str());
            std::cout << "char: " << (std::isprint(i) ? ('\'' + std::string(1, static_cast<char>(i)) + '\'') : (NPRINT)) << std::endl;
            std::cout << "int: " << i << std::endl;
        }
        float f = atof(s.c_str());
        std::cout << "float: " << f << 'f' << std::endl;
        double d = atof(s.c_str());
        std::cout << "double: " << d << std::endl;
    } catch (const std::exception& e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
