#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : elapsed_v(0), elapsed_d(0)
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
    seq_d.clear();
    seq_d_sorted.clear();
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
        seq_d = src.getSeqL();
        seq_d_sorted = src.getSeqLSorted();
        seq_v_sorted = src.getSeqVSorted();
        elapsed_v = src.getElapsedV();
        elapsed_d = src.getElapsedL();
    }
    return *this;
}

uint_vector const   & PmergeMe::getSeqV(void) const
{
    return seq_v;
}

uint_deque const     & PmergeMe::getSeqL(void) const
{
    return seq_d;
}

uint_vector const   & PmergeMe::getSeqVSorted(void) const
{
    return seq_v_sorted;
}

uint_deque const     & PmergeMe::getSeqLSorted(void) const
{
    return seq_d_sorted;
}

long long         PmergeMe::getElapsedV(void) const
{
    return elapsed_v;
}

long long         PmergeMe::getElapsedL(void) const
{
    return elapsed_d;
}

void    PmergeMe::load_v(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        seq_v.push_back(str_to_uint(av[i]));
}

void    PmergeMe::load_d(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        seq_d.push_back(str_to_uint(av[i]));
}

void PmergeMe::sort_v(void)
{
    unsigned int n = seq_v.size() & ~1;
    unsigned int half = n / 2;
    pair_vector pairs;
    uint_vector jacob_sthal_seq;

    for (unsigned int i = 0; i < n; i += 2)
    {
        uint_pair pair(seq_v[i], seq_v[i + 1]);
        if (pair.first < pair.second)
            std::swap(pair.first, pair.second);
        pairs.push_back(pair);
    }
    std::sort(pairs.begin(), pairs.end());
    for (unsigned int i = 0; i < half; i++)
        seq_v_sorted.push_back(pairs[i].first);
    gen_jacobsthal(jacob_sthal_seq, half - 1);
    seq_v_sorted.insert(seq_v_sorted.begin(), pairs[0].second);
    for (unsigned int i = 1; i < jacob_sthal_seq.size(); i++)
    {
        for (unsigned int j = jacob_sthal_seq[i]; j > jacob_sthal_seq[i - 1]; --j)
        {
            unsigned int element = pairs[j].second;
            uint_vector::iterator pos = std::upper_bound(seq_v_sorted.begin(), seq_v_sorted.end(), element);
            seq_v_sorted.insert(pos, element);
        }
    }
    if (seq_v.size() % 2 == 1)
    {
        unsigned int n1 = seq_v.back();
        uint_vector::iterator pos = std::upper_bound(seq_v_sorted.begin(), seq_v_sorted.end(), n1);
        seq_v_sorted.insert(pos, n1);
    }
}

void    PmergeMe::sort_d(void)
{
    unsigned int n = seq_d.size() & ~1;
    unsigned int half = n / 2;
    pair_deque pairs;
    uint_deque jacob_sthal_seq;

    for (unsigned int i = 0; i < n; i += 2)
    {
        uint_pair pair(seq_d[i], seq_d[i + 1]);
        if (pair.first < pair.second)
            std::swap(pair.first, pair.second);
        pairs.push_back(pair);
    }
    std::sort(pairs.begin(), pairs.end());
    for (unsigned int i = 0; i < half; i++)
        seq_d_sorted.push_back(pairs[i].first);
    gen_jacobsthal(jacob_sthal_seq, half - 1);
    seq_d_sorted.push_front(pairs[0].second);
    for (unsigned int i = 1; i < jacob_sthal_seq.size(); i++)
    {
        for (unsigned int j = jacob_sthal_seq[i]; j > jacob_sthal_seq[i - 1]; --j)
        {
            unsigned int element = pairs[j].second;
            uint_deque::iterator pos = std::upper_bound(seq_d_sorted.begin(), seq_d_sorted.end(), element);
            seq_d_sorted.insert(pos, element);
        }
    }
    if (seq_d.size() % 2 == 1)
    {
        unsigned int n1 = seq_d.back();
        uint_deque::iterator pos = std::upper_bound(seq_d_sorted.begin(), seq_d_sorted.end(), n1);
        seq_d_sorted.insert(pos, n1);
    }
}

void    PmergeMe::launchMergeInsertionSort(int ac, char **av)
{
    struct timeval  tv;
    
    gettimeofday(&tv, NULL);
    long long start = tv.tv_sec * 1000000 + tv.tv_usec;
    load_v(ac, av);
    sort_v();
    gettimeofday(&tv, NULL);
    long long end = tv.tv_sec * 1000000 + tv.tv_usec;
    elapsed_v = end - start;

    gettimeofday(&tv, NULL);
    start = tv.tv_sec * 1000000 + tv.tv_usec;
    load_d(ac, av);
    sort_d();
    gettimeofday(&tv, NULL);
    end = tv.tv_sec * 1000000 + tv.tv_usec;
    elapsed_d = end - start;
}

unsigned int     PmergeMe::str_to_uint(std::string str)
{
    std::stringstream   ss(str);
    int        n;

    if (!(ss >> n) || n < 0 || ss.rdbuf()->in_avail() != 0)
        throw std::invalid_argument("Invalid argument => " + str);
    return n;
}

void    PmergeMe::gen_jacobsthal(uint_vector & seq, unsigned int n)
{
    if (n == 0)
        return ;
    seq.push_back(0);
    if (n == 1)
        return ;
    seq.push_back(1);
    bool finished = false;
    for (unsigned int i = 2; !finished; i++)
    {
        unsigned int curr = seq[i - 1] + 2 * seq[i - 2];
        if (curr >= n)
        {
            seq.push_back(n);
            finished = true;
        }
        else
            seq.push_back(curr);
    }
}

void    PmergeMe::gen_jacobsthal(uint_deque & seq, unsigned int n)
{
    if (n == 0)
        return ;
    seq.push_back(0);
    if (n == 1)
        return ;
    seq.push_back(1);
    bool finished = false;
    for (unsigned int i = 2; !finished; i++)
    {
        unsigned int curr = seq[i - 1] + 2 * seq[i - 2];
        if (curr >= n)
        {
            seq.push_back(n);
            finished = true;
        }
        else
            seq.push_back(curr);
    }
}

std::ostream & operator<<(std::ostream & o, PmergeMe const & src)
{
    uint_vector const   & seq_v = src.getSeqV();
    uint_vector const   & seq_v_sorted = src.getSeqVSorted();
    long long         elapsed_v = src.getElapsedV();
    long long         elapsed_d = src.getElapsedL();

    o << "before:   ";
    std::copy(seq_v.begin(), seq_v.end(), std::ostream_iterator<unsigned int>(o, " "));
    o << std::endl;
    o << "after:    ";
    std::copy(seq_v_sorted.begin(), seq_v_sorted.end(), std::ostream_iterator<unsigned int>(o, " "));
    o << std::endl;
    o << "Time to process a range of " << seq_v.size() << " elements with std::vector: " << elapsed_v << " us" << std::endl;
    o << "Time to process a range of " << seq_v.size() << " elements with std::deque: " << elapsed_d << " us" << std::endl;
    return o;
}

