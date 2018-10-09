#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &inst);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &		operator=(ShrubberyCreationForm const &rhs);

	void				execute(Bureaucrat const &executor);

private:
	ShrubberyCreationForm();

};

#endif