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

	class InvalidFormCreationRequest : public std::exception
	{
		public:
			InvalidFormCreationRequest();
			InvalidFormCreationRequest(InvalidFormCreationRequest const &inst);
			virtual ~InvalidFormCreationRequest() throw();
			InvalidFormCreationRequest &	operator=(InvalidFormCreationRequest const &rhs);

			const char *what() const throw();
	};

};

#endif