#pragma once

#include <iostream>
#include <iterator>
#include <vector>

typedef std::vector<int> intVec_t;

class Span
{
    intVec_t    content;

    Span(void);

public:

    uint32_t const    max;

    Span(uint32_t n);
    Span(Span const & src);
    ~Span(void);

    Span & operator=(Span const & src);
    int   &operator[](unsigned int i);

    intVec_t::iterator  begin();
    intVec_t::const_iterator  begin() const;
    intVec_t::iterator  end();
    intVec_t::const_iterator  end() const;

    void    addNumber(int n);
    template<typename it>
    void    addNumber(it b, it e)
    {
        try
        {
            for (it i = b; i < e; i++)
                addNumber(*i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    int     shortestSpan(void) const;
    int     longestSpan(void) const;
};

std::ostream & operator<<(std::ostream & o, Span const & src);
