#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm makeTrees("School42");
	RobotomyRequestForm robotomize("Roger");
	PresidentialPardonForm pardon("Saroumane");
	Bureaucrat gandoulf("Gandoulf the Old", 1);
	Bureaucrat saroumane("Saroumane the Scum", 150);

	std::cout << makeTrees << std::endl;
	std::cout << robotomize << std::endl;
	std::cout << pardon << std::endl;

	gandoulf.executeForm(makeTrees);
	saroumane.executeForm(makeTrees);
	std::cout << std::endl;
	gandoulf.executeForm(robotomize);
	saroumane.executeForm(robotomize);
	std::cout << std::endl;
	gandoulf.executeForm(pardon);
	saroumane.executeForm(pardon);
	std::cout << std::endl;

	gandoulf.signForm(makeTrees);
	std::cout << makeTrees << std::endl;
	gandoulf.signForm(robotomize);
	std::cout << robotomize << std::endl;
	gandoulf.signForm(pardon);
	std::cout << pardon << std::endl;
	
	gandoulf.executeForm(makeTrees);
	saroumane.executeForm(makeTrees);
	std::cout << std::endl;
	gandoulf.executeForm(robotomize);
	saroumane.executeForm(robotomize);
	std::cout << std::endl;
	gandoulf.executeForm(pardon);
	saroumane.executeForm(pardon);

	return 0;
}