#include "Bureaucrat.hpp"

int main(void)
{
    {
        try
        {
            {
                Bureaucrat b("test 1", 42);
                std::cout << b << std::endl;
                b.gradeUp();
                std::cout << b << std::endl;
                b.gradeDown();
                std::cout << b << std::endl;
            }
            {
                Bureaucrat b("test 2", 37);
                std::cout << b << std::endl;
                b.gradeDown();
                std::cout << b << std::endl;
                b.gradeUp();
                std::cout << b << std::endl;
            }
            {
                Bureaucrat b("test 3", 0);
                std::cout << b << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            Bureaucrat b("test 4", 150);
            std::cout << b << std::endl;
            b.gradeDown();
            std::cout << b << std::endl;
        }
        catch(const Bureaucrat::GradeTooLowException & e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            Bureaucrat b("test 5", 1);
            std::cout << b << std::endl;
            b.gradeUp();
            std::cout << b << std::endl;
        }
        catch(const Bureaucrat::GradeTooHighException & e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}

