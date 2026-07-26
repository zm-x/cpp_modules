#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "===============================" << std::endl;
    std::cout << "VALID OBJECTS" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 42);
        Form tax("Tax Form", 50, 30);

        std::cout << bob << std::endl;
        std::cout << tax << std::endl;

        bob.signForm(tax);

        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "Form CANNOT BE SIGNED" << std::endl;
    std::cout << "===============================" << std::endl;

        Bureaucrat john("John", 100);
        Form paper("Paper", 20, 10);

        john.signForm(paper);

        std::cout << paper << std::endl;

    std::cout << "\n===============================" << std::endl;
    std::cout << "GRADE INCREMENT" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat a("Alice", 2);

        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "GRADE DECREMENT" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat a("Mike", 149);

        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "INVALID BUREAUCRAT (HIGH)" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat a("Error", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "INVALID BUREAUCRAT (LOW)" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat a("Error", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "INVALID Form (HIGH)" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Form a("Secret", 0, 20);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "INVALID Form (LOW)" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Form a("Secret", 20, 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "COPY TEST" << std::endl;
    std::cout << "===============================" << std::endl;

    try
    {
        Bureaucrat a("Original", 10);
        Bureaucrat b(a);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        Form f1("Form1", 20, 10);
        Form f2(f1);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}