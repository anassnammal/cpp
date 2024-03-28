#include "Span.hpp"

int main()
{
    Span sp(5);
    Span sp2 = Span(3);
    Span sp3(sp);
    Span sp4(1000);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp2.addNumber(sp.getContent().begin(), sp.getContent().end());
    std::cout << "sp :" << sp << std::endl;
    std::cout << "sp2 :" << sp2 << std::endl;
    std::cout << "sp3 :" << sp3 << std::endl;
    std::cout << "sp4 :" << sp4 << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        sp2[0] = 1337;
        sp2[2] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        srand(time(NULL));
        for (size_t i = 0; i < 10; i++)
            sp4[i] = rand();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "sp :" << sp << std::endl;
    std::cout << "sp2 :" << sp2 << std::endl;
    std::cout << "sp3 :" << sp3 << std::endl;
    std::cout << "sp4 :" << sp4 << std::endl;
    return 0;
}