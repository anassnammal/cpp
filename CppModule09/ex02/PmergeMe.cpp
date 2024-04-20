#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : elapsed_v(0), elapsed_l(0)
{
    // std::cout << "PmergeMe: Default constructor called" << std::endl;
    return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    // std::cout << "PmergeMe: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

PmergeMe::~PmergeMe(void)
{
    seq_v.clear();
    seq_l.clear();
    seq_l_sorted.clear();
    seq_v_sorted.clear();
    // std::cout << "PmergeMe: Destructor called" << std::endl;
    return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
    if (this != &src)
    {
        // std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
        seq_v = src.getSeqV();
        seq_l = src.getSeqL();
        seq_l_sorted = src.getSeqLSorted();
        seq_v_sorted = src.getSeqVSorted();
        elapsed_v = src.getElapsedV();
        elapsed_l = src.getElapsedL();
    }
    return *this;
}

uint_vector const   & PmergeMe::getSeqV(void) const
{
    return seq_v;
}

uint_list const     & PmergeMe::getSeqL(void) const
{
    return seq_l;
}

uint_vector const   & PmergeMe::getSeqVSorted(void) const
{
    return seq_v_sorted;
}

uint_list const     & PmergeMe::getSeqLSorted(void) const
{
    return seq_l_sorted;
}

std::time_t         PmergeMe::getElapsedV(void) const
{
    return elapsed_v;
}

std::time_t         PmergeMe::getElapsedL(void) const
{
    return elapsed_l;
}

void    PmergeMe::load_v(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        seq_v.push_back(str_to_uint(av[i]));
}

void    PmergeMe::load_l(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        seq_l.push_back(str_to_uint(av[i]));
}

void    PmergeMe::sort_v(void)
{
    
}

void    PmergeMe::sort_l(void)
{
    
}

void    PmergeMe::launchMergeInsertionSort(int ac, char **av)
{
    std::time_t     start;
    std::time_t     end;

    try
    {
        start = std::time(NULL);
        load_v(ac, av);
        sort_v();
        end = std::time(NULL);
        elapsed_v = end - start;

        start = std::time(NULL);
        load_l(ac, av);
        sort_l();
        end = std::time(NULL);
        elapsed_l = end - start;
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

unsigned int     PmergeMe::str_to_uint(char *str)
{
    std::stringstream   ss(str);
    unsigned int        n;

    if (!(ss >> n))
        throw std::invalid_argument("Invalid argument");
    return n;
}

std::ostream & operator<<(std::ostream & o, PmergeMe const & src)
{
    uint_vector const   & seq_v = src.getSeqV();
    uint_vector const   & seq_v_sorted = src.getSeqVSorted();
    std::time_t         elapsed_v = src.getElapsedV();
    std::time_t         elapsed_l = src.getElapsedL();

    o << "before:   ";
    std::copy(seq_v.begin(), seq_v.end(), std::ostream_iterator<unsigned int>(o, " "));
    o << std::endl;
    o << "after:    ";
    std::copy(seq_v_sorted.begin(), seq_v_sorted.end(), std::ostream_iterator<unsigned int>(o, " "));
    o << std::endl;
    o << "Time to process a range of " << seq_v.size() << " elements with std::vector: " << elapsed_v << "us" << std::endl;
    o << "Time to process a range of " << seq_v.size() << " elements with std::list: " << elapsed_l << "us" << std::endl;
    return o;
}

