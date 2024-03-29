#pragma once

#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:

    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

    MutantStack(void) : std::stack<T, Container>() {}
    MutantStack(const Container& cont) : std::stack<T, Container>(cont) {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    ~MutantStack(void) {}

    MutantStack& operator=(const MutantStack& src) { this->c = src.c; return *this; }
    
    MutantStack<T, Container>::iterator begin() { return this->c.begin(); }
    MutantStack<T, Container>::const_iterator begin() const { return this->c.begin(); }
    MutantStack<T, Container>::iterator end() { return this->c.end(); }
    MutantStack<T, Container>::const_iterator end() const { return this->c.end(); }

    void push_back(const T& val) { push(val); }
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const MutantStack<T>& src)
{
    std::copy(src.begin(), src.end(), std::ostream_iterator<T>(o, ", "));
    return o;
}
