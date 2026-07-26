#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;
		
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		
		std::cout << "\nTesting increment:" << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		
		std::cout << "\nTesting decrement:" << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		
		std::cout << "\nTrying to create invalid bureaucrat (grade 0):" << std::endl;
		Bureaucrat b3("Charlie", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nTrying to create invalid bureaucrat (grade 151):" << std::endl;
		Bureaucrat b4("David", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nTrying to increment grade 1:" << std::endl;
		Bureaucrat b5("Eve", 1);
		b5.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nTrying to decrement grade 150:" << std::endl;
		Bureaucrat b6("Frank", 150);
		b6.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return (0);
}
