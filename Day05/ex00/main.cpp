#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat stanley;
	std::cout << stanley << std::endl;
	stanley.incrementGrade();
	std::cout << stanley << std::endl;
	stanley.decrementGrade();
	std::cout << stanley << std::endl;

	Bureaucrat gandoulf("Gandoulf the Old", 1);
	std::cout << gandoulf << std::endl;
	gandoulf.decrementGrade();
	std::cout << gandoulf << std::endl;
	gandoulf.incrementGrade();
	std::cout << gandoulf << std::endl;

	Bureaucrat stanley2(gandoulf);
	std::cout << "Stanley 2 : " << stanley2 << std::endl;

	stanley2 = stanley;
	std::cout << "Stanley 2 : " << stanley2 << std::endl;
	
	// Exception tooHigh on creation
	try
	{
		Bureaucrat sauron("Sauron the Cheater", 0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Exception tooLow on creation
	try
	{
		Bureaucrat sauron("Saroumane the Scum", 151);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Exception tooHigh on incrementation
	try
	{
		gandoulf.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Exception tooLow on decrementation
	try
	{
		stanley.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}