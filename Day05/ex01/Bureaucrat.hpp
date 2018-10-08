#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &inst);
	~Bureaucrat();

	Bureaucrat &		operator=(Bureaucrat const &rhs);

	std::string			getName() const;
	int 				getGrade() const;

	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException();
			GradeTooHighException(GradeTooHighException const &inst);
			virtual ~GradeTooHighException() throw();
			GradeTooHighException &	operator=(GradeTooHighException const &rhs);

			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException();
			GradeTooLowException(GradeTooLowException const &inst);
			virtual ~GradeTooLowException() throw();
			GradeTooLowException &	operator=(GradeTooLowException const &rhs);

			const char *what() const throw();
	};

private:
	const std::string	_name;
	int 				_grade;

};

std::ostream &			operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif