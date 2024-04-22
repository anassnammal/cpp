#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: see usage!" << std::endl;
        std::cerr << "Usage: " << av[0] << " <positive integer>{1 2 3 ...}" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe    seq;
        seq.launchMergeInsertionSort(ac, av);
        std::cout << seq;
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

