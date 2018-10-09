#include "Intern.hpp"

/*
	Constructors and destructors
*/

Intern::Intern() { }


Intern::Intern(Intern const &inst)
{
	*this = inst;
}

Intern::~Intern() { }


/*
	Operator overloads
*/

Intern &		Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}


/*
	Member functions
*/

Form *			Intern::makeForm(std::string formName, std::string target) const
{
	if (formName == "shrubbery creation")
	{
		std::cout << "Inter creates a Shrubbery Creation Form targetted on " << target << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Inter creates a Robotomy Request Form targetted on " << target << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Inter creates a Presidential Pardon Form targetted on " << target << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Invalid form requested. Valid forms are " <<
		"\"shrubbery creation\", \"robotomy request\" and \"presidential pardon\"." << std::endl;
	}
	return NULL;
}