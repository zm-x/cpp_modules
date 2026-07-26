#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool is_signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm(const std::string &name, const int s_grade, const int e_grade);
        AForm(const AForm &AForm);
        virtual ~AForm();

        AForm &operator=(const AForm &to_copy);

        int get_sgrade() const;
        int get_egrade() const;
        bool get_issigned() const;
        const std::string &get_name() const;

        virtual void execute(Bureaucrat const &executor) const = 0;
        void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const AForm& b);

#endif