#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &inst);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &		operator=(RobotomyRequestForm const &rhs);

	void				execute(Bureaucrat const &executor);

private:
	RobotomyRequestForm();

};

#endif