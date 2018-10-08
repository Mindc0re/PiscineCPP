#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &inst);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &		operator=(PresidentialPardonForm const &rhs);

	void				execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm();

};

#endif