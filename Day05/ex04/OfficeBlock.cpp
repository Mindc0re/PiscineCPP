#include "OfficeBlock.hpp"

/* 	   *************	 */
/* GradeTooHighException */
/*	   *************	 */

OfficeBlock::MissingMemberInOfficeBlock::MissingMemberInOfficeBlock() { }

OfficeBlock::MissingMemberInOfficeBlock::MissingMemberInOfficeBlock(OfficeBlock::MissingMemberInOfficeBlock const &rhs) 
{
	*this = rhs;
}

OfficeBlock::MissingMemberInOfficeBlock::~MissingMemberInOfficeBlock() throw() { }

OfficeBlock::MissingMemberInOfficeBlock & OfficeBlock::MissingMemberInOfficeBlock::operator=(OfficeBlock::MissingMemberInOfficeBlock const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *OfficeBlock::MissingMemberInOfficeBlock::what() const throw()
{
	return "A member is missing in the office block. Bureaucracy cannot be done while this is the case.";
}


/*  *********  */
/* OfficeBlock */
/*	*********  */

/*
	Constructors and destructors
*/

OfficeBlock::OfficeBlock() :
_intern(NULL), _signingDude(NULL), _executingDude(NULL)
{ }

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *sign, Bureaucrat *exec) :
_intern(intern), _signingDude(sign), _executingDude(exec)
{ }

OfficeBlock::OfficeBlock(OfficeBlock const &inst)
{
	*this = inst;
}

OfficeBlock::~OfficeBlock() { }


/*
	Operator overloads
*/

OfficeBlock &		OfficeBlock::operator=(OfficeBlock const &rhs)
{
	(void)rhs;
	return *this;
}


/*
	Member functions
*/

void				OfficeBlock::doBureaucracy(std::string formName, std::string target) const
{
	if (!_intern || !_signingDude || !_executingDude)
		throw OfficeBlock::MissingMemberInOfficeBlock();

	Form *form = _intern->makeForm(formName, target);
	if (form == NULL)
		throw Intern::InvalidFormCreationRequest();

	_signingDude->signForm(*form);
	if (form->getIsSigned() == false)
		throw Bureaucrat::CouldNotSignForm();

	_executingDude->executeForm(*form);
	if (form->getIsExecuted() == false)
		throw Bureaucrat::CouldNotExecuteForm();

}

void				OfficeBlock::setIntern(Intern *intern)
{
	this->_intern = intern;
}

void				OfficeBlock::setSigner(Bureaucrat *newSigningDude)
{
	this->_signingDude = newSigningDude;
}

void				OfficeBlock::setExecutor(Bureaucrat *newExecutingDude)
{
	this->_executingDude = newExecutingDude;
}



