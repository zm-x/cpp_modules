#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &to_copy);
		void signForm(AForm &AForm);

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif