#include "Form.hpp"

/* 	   *************	 */
/* GradeTooHighException */
/*	   *************	 */

Form::GradeTooHighException::GradeTooHighException() { }

Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const &rhs) 
{
	*this = rhs;
}

Form::GradeTooHighException::~GradeTooHighException() throw() { }

Form::GradeTooHighException & Form::GradeTooHighException::operator=(Form::GradeTooHighException const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade indicated was too high.";
}


/* 	    *************	  */
/*  GradeTooLowException  */
/*	    *************	  */

Form::GradeTooLowException::GradeTooLowException() { }

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const &rhs) 
{
	*this = rhs;
}

Form::GradeTooLowException::~GradeTooLowException() throw() { }

Form::GradeTooLowException & Form::GradeTooLowException::operator=(Form::GradeTooLowException const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade indicated was too low.";
}

/*   ***********   */
/*  FormNotSigned  */
/*	 ***********   */

Form::FormNotSigned::FormNotSigned() { }

Form::FormNotSigned::FormNotSigned(Form::FormNotSigned const &rhs) 
{
	*this = rhs;
}

Form::FormNotSigned::~FormNotSigned() throw() { }

Form::FormNotSigned & Form::FormNotSigned::operator=(Form::FormNotSigned const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Form::FormNotSigned::what() const throw()
{
	return "The form is not signed.";
}


/*   **	  */
/*  Form  */
/*	 **	  */

/*
	Constructors and destructors
*/

Form::Form() :
_name("Laisser-passer A38"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false) { }

Form::Form(std::string name, int toSign, int toExecute) : 
_name(name), _gradeToSign(toSign), _gradeToExecute(toExecute), _isSigned(false)
{
	if (toSign > 150 || toExecute > 150)
		throw Form::GradeTooLowException();
	else if (toSign < 1 || toExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &inst) : 
_name(inst._name), _gradeToSign(inst._gradeToSign), _gradeToExecute(inst._gradeToExecute)
{
	*this = inst;
}

Form::~Form() { }


/*
	Operator overloads
*/

Form &				Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs._isSigned;

	return *this;
}

std::ostream &		operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << " form requires a level " << rhs.getGradeToSign() << " grade to be signed, and a level " 
	<< rhs.getGradeToExecute() << " grade to be executed. It is actually " 
	<< ((rhs.getIsSigned()) ? "signed.": "not signed.") << std::endl;

	return o;
}


/*
	Member functions
*/

std::string 		Form::getName() const
{
	return _name;
}

int 				Form::getGradeToSign() const
{
	return _gradeToSign;
}

int 				Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool				Form::getIsSigned() const
{
	return _isSigned;
}

std::string 		Form::getTarget() const
{
	return _target;
}

void				Form::setTarget(std::string targetToSet)
{
	this->_target = targetToSet;
}

void				Form::setSigned(bool signedToSet)
{
	this->_isSigned = signedToSet;
}

void				Form::beSigned(Bureaucrat guyWhoSigns)
{
	if (guyWhoSigns.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

