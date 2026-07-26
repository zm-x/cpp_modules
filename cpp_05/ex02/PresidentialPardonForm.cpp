#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), target(copy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!get_issigned())
		throw FormNotSignedException();
	if (executor.getGrade() > get_egrade())
		throw GradeTooLowException();

	std::cout << target
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}