#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name,
						const std::string &target)
{
	std::string forms[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*functions[3])(const std::string &) =
	{
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*functions[i])(target);
		}
	}
 
	std::cout << "Intern couldn't create " << name << std::endl;
	return NULL;
}