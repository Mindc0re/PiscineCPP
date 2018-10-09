#include "RobotomyRequestForm.hpp"

/*
	Constructors and destructors
*/

RobotomyRequestForm::RobotomyRequestForm() : Form()
{ }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &inst)
{
	*this = inst;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}


/*
	Operator overloads
*/

RobotomyRequestForm &		RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->setSigned(rhs.getIsSigned());
	this->setTarget(rhs.getTarget());

	return *this;
}


/*
	Member functions
*/

void			RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() == false)
		throw Form::FormNotSigned();
	else if (this->getIsSigned() == false || executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();

	srand(time(NULL));
	int success = rand() % 2;

	if (success == 0)
		std::cout << "*drilling noises* ... " << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomization process failed." << std::endl;
}