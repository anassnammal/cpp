#pragma once

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

typedef std::vector<unsigned int>               uint_vector;
typedef std::list<unsigned int>                 uint_list;
typedef std::pair<unsigned int, unsigned int>   uint_pair;
typedef std::vector<uint_pair>                  pair_vector;
typedef std::list<uint_pair>                    pair_list;

class PmergeMe
{
    uint_vector seq_v;
    uint_list   seq_l;

    uint_vector seq_v_sorted;
    uint_list   seq_l_sorted;

    std::time_t elapsed_v;
    std::time_t elapsed_l;

public:
    PmergeMe(void);
    PmergeMe(PmergeMe const & src);
    ~PmergeMe(void);

    PmergeMe & operator=(PmergeMe const & src);

    uint_vector const   & getSeqV(void) const;
    uint_list const     & getSeqL(void) const;
    uint_vector const   & getSeqVSorted(void) const;
    uint_list const     & getSeqLSorted(void) const;
    std::time_t         getElapsedV(void) const;
    std::time_t         getElapsedL(void) const;

    void    load_v(int ac, char **av);
    void    load_l(int ac, char **av);

    void    sort_v(void);
    void    sort_l(void);

    void    launchMergeInsertionSort(int ac, char **av);

    static unsigned int     str_to_uint(char *str);
};

std::ostream & operator<<(std::ostream & o, PmergeMe const & src);

