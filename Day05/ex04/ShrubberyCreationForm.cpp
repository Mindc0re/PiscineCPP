#include "ShrubberyCreationForm.hpp"

/*
	Constructors and destructors
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{ }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &inst)
{
	*this = inst;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}


/*
	Operator overloads
*/

ShrubberyCreationForm &		ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->setSigned(rhs.getIsSigned());
	this->setTarget(rhs.getTarget());

	return *this;
}


/*
	Member functions
*/

void			ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() == false)
		throw Form::FormNotSigned();
	else if (this->getIsSigned() == false || executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream file(filename);

	if (file.is_open())
	{
		file <<
		"              ,@@@@@@@,				 \n" <<
		"      ,,,.   ,@@@@@@/@@,  .oo8888o.	 \n" <<
		"   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o	 \n" <<
		"  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	 \n" <<
		"  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' 	 \n" <<
		"  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' 	 \n" <<
		"  `&%\\ ` /%&'    |.|        \\ '|8'		 \n" <<
		"      |o|        | |         | |		 \n" <<
		"      |.|        | |         | |		 \n" <<
		"   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n" << std::endl;
		file.close();
	}

}