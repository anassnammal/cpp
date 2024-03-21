#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137)
{
    // std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
    // std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    // std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
    return ;
}

void            ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkRequirement(executor);
    
    std::string     filename;
    std::string     asciiTree;
    std::ofstream   file;

    filename = this->getName() + "_shrubbery";
    try
    {
        file.open(filename, std::ios::out | std::ios::trunc);
        file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        asciiTree = "\n      /\\      \n     /\\*\\     \n    /\\O\\*\\    \n   /*/\\/\\/\\   \n  /\\O\\/\\*\\/\\  \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*/\\/O/\\\n      ||      \n      ||      \n      ||      \n";
        file << asciiTree;
        file.close();
    }
    catch(const std::ios::failure &fail)
    {
        std::cerr << "couldn't create " << filename << "because of: " << fail.what() << std::endl;
    }
}

// std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src)
// {
//     o << "ostream operator called";
//     return o;
// }

