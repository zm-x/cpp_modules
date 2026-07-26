#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int s_grade, const int e_grade)
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

Form::Form(const Form &Form)
    : _name(Form._name),
      is_signed(Form.is_signed),
      _signGrade(Form._signGrade),
      _executeGrade(Form._executeGrade)
{
}

Form::~Form()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > get_sgrade())
        throw GradeTooLowException();
    is_signed = true;
}

Form &Form::operator=(const Form &to_copy)
{
    if (this != &to_copy)
        is_signed = to_copy.is_signed;
    return *this;
}

int Form::get_egrade() const
{
    return _executeGrade;
}

bool Form::get_issigned() const
{
    return is_signed;
}

int Form::get_sgrade() const
{
    return _signGrade;
}

const std::string &Form::get_name() const
{
    return _name;
}

std::ostream &operator<<(std::ostream& out, const Form& f)
{
	out << f.get_name() << ", " << f.get_sgrade();
    out << ", " << f.get_egrade() << ", " << f.get_issigned();
	return out;
}