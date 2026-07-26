#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "===============================" << std::endl;
	std::cout << "SHRUBBERY SUCCESS" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm tree("home");

		bob.signForm(tree);
		bob.executeForm(tree);

		std::cout << "Check file: home_shrubbery" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "ROBOTOMY SUCCESS / FAILURE" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		RobotomyRequestForm robot("Bender");

		alice.signForm(robot);

		for (int i = 0; i < 5; i++)
			alice.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "PRESIDENTIAL PARDON" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "EXECUTE WITHOUT SIGNING" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm tree("garden");

		bob.executeForm(tree);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "SIGN FAILED" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat low("Low", 150);
		PresidentialPardonForm pardon("Ford");

		low.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "EXECUTE FAILED (GRADE TOO LOW)" << std::endl;
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 140);

		ShrubberyCreationForm tree("office");

		boss.signForm(tree);
		worker.executeForm(tree);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}