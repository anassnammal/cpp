#include "ScalarConverter.hpp"

int main(int ac, const char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR!" << std::endl << "USAGE: ./convert <input>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}

