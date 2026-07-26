#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Intern
{
	private:
		AForm *makeShrubbery(const std::string &target);
		AForm *makeRobotomy(const std::string &target);
		AForm *makePresidential(const std::string &target);

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern &operator=(const Intern &copy);

		AForm *makeForm(const std::string &name,
						const std::string &target);
};

#endif