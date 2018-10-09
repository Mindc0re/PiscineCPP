#include "PresidentialPardonForm.hpp"

/*
	Constructors and destructors
*/

PresidentialPardonForm::PresidentialPardonForm() : Form()
{ }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &inst)
{
	*this = inst;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


/*
	Operator overloads
*/

PresidentialPardonForm &		PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->setSigned(rhs.getIsSigned());
	this->setExecuted(rhs.getIsExecuted());
	this->setTarget(rhs.getTarget());

	return *this;
}


/*
	Member functions
*/

void			PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > this->getGradeToExecute())
		return ;

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	this->setExecuted(true);
}