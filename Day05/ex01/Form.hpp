#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form();
	Form(std::string name, int toSign, int toExecute);
	Form(Form const &inst);
	~Form();

	Form &				operator=(Form const &rhs);

	std::string 		getName() const;
	int 				getGradeToSign() const;
	int 				getGradeToExecute() const;
	bool				getIsSigned() const;

	void				beSigned(Bureaucrat guyWhoSigns);

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException();
			GradeTooHighException(GradeTooHighException const &inst);
			~GradeTooHighException() throw();
			GradeTooHighException &	operator=(GradeTooHighException const &rhs);

			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException();
			GradeTooLowException(GradeTooLowException const &inst);
			~GradeTooLowException() throw();
			GradeTooLowException &	operator=(GradeTooLowException const &rhs);

			const char *what() const throw();
	};

private:
	const std::string	_name;
	const int 			_gradeToSign;
	const int 			_gradeToExecute;
	bool 				_isSigned;

};

std::ostream &			operator<<(std::ostream &o, Form const &rhs);

#endif