#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool is_signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form(const std::string &name, const int s_grade, const int e_grade);
        Form(const Form &Form);
        ~Form();

        Form &operator=(const Form &to_copy);

        int get_sgrade() const;
        int get_egrade() const;
        bool get_issigned() const;
        const std::string &get_name() const;

        void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const Form& b);

#endif