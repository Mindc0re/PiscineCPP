#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern *idiotOne = new Intern();
	Bureaucrat *stanley = new Bureaucrat("Stanley", 26);
	Bureaucrat *gandoulf = new Bureaucrat("Gandoulf the Old", 6);
	OfficeBlock office;

	try
	{
		office.doBureaucracy("robotomy request", "Bender");
	}
	catch (OfficeBlock::MissingMemberInOfficeBlock &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	OfficeBlock office2(idiotOne, stanley, gandoulf);

	office2.setIntern(idiotOne);
	office2.setSigner(stanley);
	office2.setExecutor(gandoulf);

	try
	{
		office2.doBureaucracy("yolo form", "yolo");
	}
	catch (Intern::InvalidFormCreationRequest &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		office2.doBureaucracy("presidential pardon", "Gollum");
	}
	catch (Bureaucrat::CouldNotSignForm &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	stanley->incrementGrade();

	try
	{
		office2.doBureaucracy("presidential pardon", "Gollum");
	}
	catch (Bureaucrat::CouldNotExecuteForm &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	gandoulf->incrementGrade();

	try
	{
		office2.doBureaucracy("presidential pardon", "Gollum");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}	

	delete(idiotOne);
	delete(stanley);
	delete(gandoulf);

	return 0;
}