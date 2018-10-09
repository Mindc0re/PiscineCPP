#include "Intern.hpp"

/* 	   *************	 */
/* GradeTooHighException */
/*	   *************	 */

Intern::InvalidFormCreationRequest::InvalidFormCreationRequest() { }

Intern::InvalidFormCreationRequest::InvalidFormCreationRequest(Intern::InvalidFormCreationRequest const &rhs) 
{
	*this = rhs;
}

Intern::InvalidFormCreationRequest::~InvalidFormCreationRequest() throw() { }

Intern::InvalidFormCreationRequest & Intern::InvalidFormCreationRequest::operator=(Intern::InvalidFormCreationRequest const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Intern::InvalidFormCreationRequest::what() const throw()
{
	return "Intern tried to create an invalid form. Valid forms are \"shrubbery creation\", \"robotomy request\" and \"presidential pardon\".";
}


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
		std::cout << "Intern creates a Shrubbery Creation Form targetted on " << target << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates a Robotomy Request Form targetted on " << target << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates a Presidential Pardon Form targetted on " << target << std::endl;
		return new PresidentialPardonForm(target);
	}
	
	return NULL;
}