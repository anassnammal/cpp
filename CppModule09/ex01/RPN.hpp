#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stack>

class RPN
{
    std::stack<int> stack;


public:
    RPN(void);
    RPN(RPN const & src);
    ~RPN(void);

    RPN & operator=(RPN const & src);

    void push(int value);
    int  pop(void);
    bool empty(void) const;
    
    void add(void);
    void sub(void);
    void mul(void);
    void div(void);

    class RPNException : public std::exception
    {
        std::string msg;

    public:
        RPNException(std::string const & msg);
        virtual ~RPNException(void) throw();
        virtual const char * what(void) const throw();
    };
};

// std::ostream & operator<<(std::ostream & o, RPN const & src);

