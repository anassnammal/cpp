// #include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: see usage!" << std::endl;
        std::cerr << "Usage: " << av[0] << "<positive integer>{1, 2, 3, ...}" << std::endl;
        return 1;
    }
    return 0;
}

