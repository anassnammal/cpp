#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR: need input file name" << std::endl;
        std::cerr << "Usage: ./bitcoin [inputFile]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange(av[1]);
    return 0;
}

