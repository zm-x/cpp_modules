#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137) , _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
    : AForm(copy), _target(copy._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
        if (this != &copy)
            AForm::operator=(copy);
    return *this;   
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!get_issigned())
        throw FormNotSignedException();
    if (executor.getGrade() > get_egrade())
        throw GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        return;

    file << "       /\\\n";
    file << "      /**\\\\\n";
    file << "     /****\\\\\n";
    file << "    /******\\\\\n";
    file << "       ||\n";
    file << "       ||\n";
}