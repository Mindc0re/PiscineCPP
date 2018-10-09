#include "Bureaucrat.hpp"

/* 	   *************	 */
/* GradeTooHighException */
/*	   *************	 */

Bureaucrat::GradeTooHighException::GradeTooHighException() { }

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const &rhs) 
{
	*this = rhs;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade requested was too high.";
}


/* 	    *************	  */
/*  GradeTooLowException  */
/*	    *************	  */

Bureaucrat::GradeTooLowException::GradeTooLowException() { }

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const &rhs) 
{
	*this = rhs;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade requested was too low.";
}

/* 	 **************	  */
/*  CouldNotSignForm  */
/*	 **************	  */

Bureaucrat::CouldNotSignForm::CouldNotSignForm() { }

Bureaucrat::CouldNotSignForm::CouldNotSignForm(Bureaucrat::CouldNotSignForm const &rhs) 
{
	*this = rhs;
}

Bureaucrat::CouldNotSignForm::~CouldNotSignForm() throw() { }

Bureaucrat::CouldNotSignForm & Bureaucrat::CouldNotSignForm::operator=(Bureaucrat::CouldNotSignForm const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Bureaucrat::CouldNotSignForm::what() const throw()
{
	return "The bureaucrat could not sign the form because his grade is too low.";
}

/*   ****************    */
/*  CouldNotExecuteForm  */
/*	 ****************    */

Bureaucrat::CouldNotExecuteForm::CouldNotExecuteForm() { }

Bureaucrat::CouldNotExecuteForm::CouldNotExecuteForm(Bureaucrat::CouldNotExecuteForm const &rhs) 
{
	*this = rhs;
}

Bureaucrat::CouldNotExecuteForm::~CouldNotExecuteForm() throw() { }

Bureaucrat::CouldNotExecuteForm & Bureaucrat::CouldNotExecuteForm::operator=(Bureaucrat::CouldNotExecuteForm const &rhs) 
{
	(void)rhs;
	return *this;
}

const char *Bureaucrat::CouldNotExecuteForm::what() const throw()
{
	return "The bureaurat could not execute the form because his grade is too low.";
}

/*  **********  */
/*  Bureaucrat  */
/*  **********	*/

/*
	Constructors and destructors
*/

Bureaucrat::Bureaucrat() : _name("Stanley"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &inst) : _name(inst._name)
{
	*this = inst;
}

Bureaucrat::~Bureaucrat() { }




/*
	Operator overloads
*/

Bureaucrat &		Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;

	return *this;
}

std::ostream &		operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;

	return o;
}


/*
	Member functions
*/

std::string 		Bureaucrat::getName() const
{
	return _name;
}

int 				Bureaucrat::getGrade() const
{
	return _grade;
}

void				Bureaucrat::incrementGrade()
{
	if ((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if ((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void				Bureaucrat::signForm(Form &form) const
{
	form.beSigned(*this);
}

void				Bureaucrat::executeForm(Form &form) const
{
	form.execute(*this);
}