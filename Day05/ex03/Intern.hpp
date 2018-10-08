#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern const &inst);
	~Intern();

	Intern &		operator=(Intern const &rhs);

	Form *			makeForm(std::string formName, std::string target) const;

};

#endif