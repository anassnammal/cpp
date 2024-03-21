#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("test", 6);
        ShrubberyCreationForm   f1("form 1");
        RobotomyRequestForm     f2("form 2");
        PresidentialPardonForm  f3("form 3");

        b.signForm(f1);
        b.executeForm(f1);
        b.executeForm(f2);
        b.signForm(f2);
        b.executeForm(f2);
        b.executeForm(f2);
        b.executeForm(f2);
        b.executeForm(f2);
        b.signForm(f3);
        b.executeForm(f3);
        b.gradeUp();
        b.executeForm(f3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

