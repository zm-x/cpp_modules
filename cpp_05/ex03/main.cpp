#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "===============================" << std::endl;
	std::cout << "VALID FORM CREATION" << std::endl;
	std::cout << "===============================" << std::endl;

	Intern intern;

	AForm *form1 = intern.makeForm("shrubbery creation", "home");
	AForm *form2 = intern.makeForm("robotomy request", "Bender");
	AForm *form3 = intern.makeForm("presidential pardon", "Arthur");

	delete form1;
	delete form2;
	delete form3;

	std::cout << "\n===============================" << std::endl;
	std::cout << "INVALID FORM NAME" << std::endl;
	std::cout << "===============================" << std::endl;

	AForm *invalid = intern.makeForm("pizza form", "Italy");

	if (!invalid)
		std::cout << "Returned NULL as expected." << std::endl;

	delete invalid;

	std::cout << "\n===============================" << std::endl;
	std::cout << "FULL EXECUTION TEST" << std::endl;
	std::cout << "===============================" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *shrub = intern.makeForm("shrubbery creation", "garden");
		AForm *robot = intern.makeForm("robotomy request", "Marvin");
		AForm *pres = intern.makeForm("presidential pardon", "Ford");

		boss.signForm(*shrub);
		boss.signForm(*robot);
		boss.signForm(*pres);

		boss.executeForm(*shrub);
		boss.executeForm(*robot);
		boss.executeForm(*pres);

		delete shrub;
		delete robot;
		delete pres;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "EXECUTE UNSIGNED FORM" << std::endl;
	std::cout << "===============================" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *form = intern.makeForm("robotomy request", "Wall-E");

		boss.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===============================" << std::endl;
	std::cout << "LOW GRADE TEST" << std::endl;
	std::cout << "===============================" << std::endl;

	try
	{
		Bureaucrat low("Low", 150);

		AForm *form = intern.makeForm("shrubbery creation", "school");

		low.signForm(*form);
		low.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}