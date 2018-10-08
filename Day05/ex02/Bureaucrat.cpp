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
	try
	{
		form.beSigned(*this);

		std::cout << _name << " signed " << form.getName() << " successfully !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " could not sign " << form.getName() << " because \"" << e.what() << "\"" << std::endl;
	}
}

void				Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);

		std::cout << _name << " executed " << form.getName() << " on " << form.getTarget() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " could not execute " << form.getName() << " because \"" << e.what() << "\"" << std::endl; 
	}
}