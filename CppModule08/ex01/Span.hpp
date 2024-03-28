#pragma once

#include <iostream>
#include <iterator>
#include <vector>

typedef std::vector<int> intVec_t;

class Span
{
    intVec_t    content;
    uint32_t    max;

    Span(void);
    Span & operator=(Span const & src);

public:
    Span(uint32_t n);
    Span(Span const & src);
    ~Span(void);

    int   &operator[](unsigned int i);

    intVec_t const    &getContent(void) const;
    uint32_t          getMax(void) const;

    void    addNumber(int n);
    template<typename it>
    void    addNumber(it b, it e);
    int     shortestSpan(void) const;
    int     longestSpan(void) const;
};

std::ostream & operator<<(std::ostream & o, Span const & src);
