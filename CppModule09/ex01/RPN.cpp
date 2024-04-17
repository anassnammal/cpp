#include "RPN.hpp"

RPN::RPN(void)
{
    // std::cout << "RPN: Default constructor called" << std::endl;
    return ;
}

RPN::RPN(RPN const & src)
{
    // std::cout << "RPN: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

RPN::~RPN(void)
{
    // std::cout << "RPN: Destructor called" << std::endl;
    return ;
}

RPN & RPN::operator=(RPN const & src)
{
    if (this != &src)
    {
        // std::cout << "RPN: Copy assignment operator called" << std::endl;
        stack = src.stack;
    }
    return *this;
}

void RPN::push(int value)
{
    stack.push(value);
    return ;
}

int RPN::pop(void)
{
    if (stack.empty())
        throw RPNException("invalid RPN expression");
    int value = stack.top();
    stack.pop();
    return value;
}

bool RPN::empty(void) const
{
    return stack.empty();
}

void RPN::add(void)
{
    int a = pop();
    int b = pop();
    push(a + b);
    return ;
}

void RPN::sub(void)
{
    int a = pop();
    int b = pop();
    push(b - a);
    return ;
}

void RPN::mul(void)
{
    int a = pop();
    int b = pop();
    push(a * b);
    return ;
}

void RPN::div(void)
{
    int a = pop();
    int b = pop();
    push(b / a);
    return ;
}

RPN::RPNException::RPNException(std::string const & msg) : msg(msg)
{
    // std::cout << "RPNException: Parameter constructor called" << std::endl;
    return ;
}

RPN::RPNException::~RPNException(void) throw()
{
    // std::cout << "RPNException: Destructor called" << std::endl;
    return ;
}

const char * RPN::RPNException::what(void) const throw()
{
    return msg.c_str();
}