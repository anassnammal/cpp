#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("test", 6);
        Intern  i;

        try
        {
            AForm   *form = i.makeForm("shrubbery creation", "form 1");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::FormNotValid &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            AForm   *form = i.makeForm("robotomy request", "form 2");
            b.executeForm(*form);
            b.signForm(*form);
            b.executeForm(*form);
            b.executeForm(*form);
            b.executeForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::FormNotValid &e)
        {
            std::cout << e.what() << std::endl;
        }
        
        try
        {
            AForm   *form = i.makeForm("presidential pardon", "form 3");
            b.signForm(*form);
            b.executeForm(*form);
            b.gradeUp();
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::FormNotValid &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            AForm   *form = i.makeForm("invalid form", "form 4");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::FormNotValid &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

