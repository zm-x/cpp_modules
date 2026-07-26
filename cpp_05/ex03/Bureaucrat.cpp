#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name , int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_copy)
{
	if (this != &to_copy)
		_grade = to_copy._grade;
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't execute "
				  << form.get_name() << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << getName() << " signed " << AForm.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn't sign " << AForm.get_name()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}