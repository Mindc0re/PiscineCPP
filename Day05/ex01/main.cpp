#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form pactWithTheDevil("Pact with the Devil", -666, -666);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form falseForm("False Form", 404, 404);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat gandoulf("Gandoulf the Old", 2);
	std::cout << gandoulf << std::endl;

	Form peaceTreaty("Peace Treaty", 1, 1);
	std::cout << peaceTreaty << std::endl;

	Form warTreaty("War Treaty", 150, 150);
	std::cout << warTreaty << std::endl;

	gandoulf.signForm(peaceTreaty);
	std::cout << peaceTreaty << std::endl;
	
	gandoulf.incrementGrade();
	std::cout << gandoulf << std::endl;
	gandoulf.signForm(peaceTreaty);
	std::cout << peaceTreaty << std::endl;

	Form peaceTreaty2(peaceTreaty);
	std::cout << peaceTreaty << std::endl;

	warTreaty = peaceTreaty2;
	std::cout << warTreaty << std::endl;

	return 0;
}