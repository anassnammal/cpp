#include "Span.hpp"

Span::Span(uint32_t n) : max(n)
{
    // std::cout << "Span: Default constructor called" << std::endl;
    return ;
}

Span::Span(Span const & src) : max(src.getMax())
{
    // std::cout << "Span: Copy constructor called" << std::endl;
    intVec_t    tmp = src.getContent();
    content.insert(tmp.begin(), tmp.end());
    return ;
}

Span::~Span(void)
{
    // std::cout << "Span: Destructor called" << std::endl;
    return ;
}

intVec_t const  &Span::getContent(void) const
{
    return (content);
}

uint32_t        Span::getMax(void) const
{
    return (max);
}

void            Span::addNumber(int n)
{
    try
    {
        if (content.size() >= max)
            throw std::out_of_range("OUT OF RANGE! span is full");
        content.push_back(n);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template<typename it>
void            Span::addNumber(it b, it e)
{
    for (it i = b; i < e; i++)
    {
        try
        {
            if (content.size() >= max)
                throw std::out_of_range("OUT OF RANGE! span is full");
            content.push_back(*i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            break ;
        }
    }
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
    int min = *std::min_element(content.begin(), content.end());
    int max = *std::max_element(content.begin(), content.end());
    return (max - min);
}

int   &Span::operator[](unsigned int i)
{
    if (i >= content.size())
        throw std::out_of_range("Span index out of range");
    return content[i];
}

std::ostream & operator<<(std::ostream & o, Span const & src)
{
    intVec_t const  &tmp = src.getContent();
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<int>(o, ", "));
    return o;
}

