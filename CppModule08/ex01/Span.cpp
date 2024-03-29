#include "Span.hpp"

Span::Span(uint32_t n) : max(n)
{
    // std::cout << "Span: Default constructor called" << std::endl;
    return ;
}

Span::Span(Span const & src) : max(src.max)
{
    // std::cout << "Span: Copy constructor called" << std::endl;
    addNumber(src.begin(), src.end());
    return ;
}

Span::~Span(void)
{
    // std::cout << "Span: Destructor called" << std::endl;
    return ;
}

intVec_t::iterator  Span::begin()
{
    return (content.begin());
}

intVec_t::const_iterator  Span::begin() const
{
    return (content.begin());
}

intVec_t::iterator  Span::end()
{
    return (content.end());
}

intVec_t::const_iterator  Span::end() const
{
    return (content.end());
}

void            Span::addNumber(int n)
{
    if (content.size() >= max)
        throw std::out_of_range("Error! Span is full");
    content.push_back(n);
}

int     Span::shortestSpan(void) const
{
    intVec_t    sorted = content;
    std::stable_sort(sorted.begin(), sorted.end());
    int ss = *(sorted.begin() + 1) - *sorted.begin();
    for (intVec_t::const_iterator i = sorted.begin() + 2; i < sorted.end(); i++)
    {
        int css = *i - *(i - 1);
        if (css < ss)
            ss = css;
    }
    return ss;
}

int     Span::longestSpan(void) const
{
    int min = *std::min_element(begin(), end());
    int max = *std::max_element(begin(), end());
    return (max - min);
}

Span & Span::operator=(Span const & src)
{
    // std::cout << "Span: Copy assignment called" << std::endl;
    if (this != &src)
    {
        addNumber(src.begin(), src.end());
    }
    return (*this);
}

int   &Span::operator[](unsigned int i)
{
    if (i >= max)
        throw std::out_of_range("Error! Span index out of range");
    else if (i == content.size())
        content.push_back(0);
    return content[i];
}

std::ostream & operator<<(std::ostream & o, Span const & src)
{
    std::copy(src.begin(), src.end(), std::ostream_iterator<int>(o, ", "));
    return o;
}

