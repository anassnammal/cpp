#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "ERROR: No arguments provided" << std::endl;
        std::cerr << "USAGE: ./RPN \"[RPN expression]\"" << std::endl;
        return 1;
    }
    RPN rpn;
    std::string expr = av[1];
    try
    {
        for (size_t i = 0; i < expr.length(); i++)
        {
            if (expr[i] == ' ')
                continue;
            if (isdigit(expr[i]) && (i == 0 || expr[i - 1] == ' ')
                && (i == expr.length() - 1 || expr[i + 1] == ' '))
            {
                rpn.push(atoi(&expr[i]));
                while (isdigit(expr[i + 1]))
                    i++;
            }
            else if (expr[i] == '+')
                rpn.add();
            else if (expr[i] == '-')
                rpn.sub();
            else if (expr[i] == '*')
                rpn.mul();
            else if (expr[i] == '/')
                rpn.div();
            else
                throw RPN::RPNException("invalid RPN expression");
        }
        int result = rpn.pop();
        if (!rpn.empty())
            throw RPN::RPNException("invalid RPN expression");
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    return 0;
}

