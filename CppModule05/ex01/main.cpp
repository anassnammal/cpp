#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("test", 42);
        Form f1("form1", 42, 42);
        Form f2("form2", 1, 1);
        std::cout << b << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        b.signForm(f1);
        b.signForm(f2);
        b.signForm(f1);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

