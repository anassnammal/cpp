#pragma once

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

typedef std::vector<unsigned int>               uint_vector;
typedef std::deque<unsigned int>                uint_deque;
typedef std::pair<unsigned int, unsigned int>   uint_pair;
typedef std::vector<uint_pair>                  pair_vector;
typedef std::deque<uint_pair>                   pair_deque;

class PmergeMe
{
    uint_vector seq_v;
    uint_deque   seq_d;

    uint_vector seq_v_sorted;
    uint_deque   seq_d_sorted;

    std::time_t elapsed_v;
    std::time_t elapsed_d;

public:
    PmergeMe(void);
    PmergeMe(PmergeMe const & src);
    ~PmergeMe(void);

    PmergeMe & operator=(PmergeMe const & src);

    uint_vector const   & getSeqV(void) const;
    uint_deque const     & getSeqL(void) const;
    uint_vector const   & getSeqVSorted(void) const;
    uint_deque const     & getSeqLSorted(void) const;
    std::time_t         getElapsedV(void) const;
    std::time_t         getElapsedL(void) const;

    void    load_v(int ac, char **av);
    void    load_d(int ac, char **av);

    void    sort_v(void);
    void    sort_d(void);

    void    launchMergeInsertionSort(int ac, char **av);

    static unsigned int     str_to_uint(char *str);
    static void             gen_jacobsthal(uint_vector & seq, unsigned int n);
    static void             gen_jacobsthal(uint_deque & seq, unsigned int n);
};

std::ostream & operator<<(std::ostream & o, PmergeMe const & src);

