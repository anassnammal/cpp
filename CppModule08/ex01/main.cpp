#include "Span.hpp"

int main()
{
    Span sp(5);
    Span sp2(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp2.addNumber(sp.begin(), sp.end());
    std::cout << "sp :" << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "sp2 :" << sp2 << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    sp2[0] = 1337;
    sp2[2] = 42;
    std::cout << "sp :" << sp << std::endl;
    std::cout << "sp2 :" << sp2 << std::endl;
    Span sp3(sp);
    Span sp4(10);
    Span sp5(5);
    sp5 = sp2;
    sp5[4] = 555;
    srand(time(NULL));
    for (size_t i = 0; i < 10; i++)
        sp4[i] = rand() % 100;
    std::cout << "sp3 :" << sp3 << std::endl;
    std::cout << "sp4 :" << sp4 << std::endl;
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;
    std::cout << "sp5 :" << sp5 << std::endl;
    std::cout << sp5.shortestSpan() << std::endl;
    std::cout << sp5.longestSpan() << std::endl;
    return 0;
}