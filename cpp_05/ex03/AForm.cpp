#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const int s_grade, const int e_grade)
    : _name(name),
      is_signed(false),
      _signGrade(s_grade),
      _executeGrade(e_grade)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &AForm)
    : _name(AForm._name),
      is_signed(AForm.is_signed),
      _signGrade(AForm._signGrade),
      _executeGrade(AForm._executeGrade)
{
}

AForm::~AForm()
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > get_sgrade())
        throw GradeTooLowException();
    is_signed = true;
}

AForm &AForm::operator=(const AForm &to_copy)
{
    if (this != &to_copy)
        is_signed = to_copy.is_signed;
    return *this;
}

int AForm::get_egrade() const
{
    return _executeGrade;
}

bool AForm::get_issigned() const
{
    return is_signed;
}

int AForm::get_sgrade() const
{
    return _signGrade;
}

const std::string &AForm::get_name() const
{
    return _name;
}

std::ostream &operator<<(std::ostream& out, const AForm& f)
{
	out << f.get_name() << ", " << f.get_sgrade();
    out << ", " << f.get_egrade() << ", " << f.get_issigned();
	return out;
}