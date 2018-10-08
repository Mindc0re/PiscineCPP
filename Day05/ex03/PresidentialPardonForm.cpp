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
	this->setTarget(rhs.getTarget());

	return *this;
}


/*
	Member functions
*/

void			PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw Form::FormNotSigned();
	else if (this->getIsSigned() == false || executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}