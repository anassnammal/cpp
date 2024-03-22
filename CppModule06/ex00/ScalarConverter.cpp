#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const s)
{
    if (s.find("nan") != std::string::npos || s.find("+inf") != std::string::npos || s.find("-inf") != std::string::npos)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(atof(s.c_str())) << 'f' << std::endl;
        std::cout << "double: " << atof(s.c_str()) << std::endl;
    }
    else if (s.length() == 1 && !isdigit(s.at(0)))
    {
        char c = s.at(0);
        std::cout << "char: " << (std::isprint(c) ? ('\'' + std::string(1, c) + '\'') : ("not displayable")) << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (s.find('.') != s.npos)
    {
        if (s.find('f') != s.npos)
        {
            float f = static_cast<float>((atof(s.c_str())));
            std::cout << "char: " << (std::isprint(static_cast<char>(f)) ? ('\'' + std::string(1, static_cast<char>(f)) + '\'') : ("not displayable")) << std::endl;
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            if (f == floor(f))
                std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << 'f' << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
        else
        {
            double d = static_cast<double>((atof(s.c_str())));
            std::cout << "char: " << (std::isprint(static_cast<char>(d)) ? ('\'' + std::string(1, static_cast<char>(d)) + '\'') : ("not displayable")) << std::endl;
            std::cout << "int: " << static_cast<int>(d) << std::endl;
            if (d == floor(d))
                std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
            std::cout << "double: " << d << std::endl;
        }
    }
    else
    {
        int i = atoi(s.c_str());
        std::cout << "char: " << (std::isprint(i) ? ('\'' + std::string(1, static_cast<char>(i)) + '\'') : ("not displayable")) << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
}
