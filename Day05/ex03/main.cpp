#include "Form.hpp"
#include "Intern.hpp"

int main()
{
	Intern	randomIntern;

	Form *shrub = randomIntern.makeForm("shrubbery creation", "School42");
	Form *robot = randomIntern.makeForm("robotomy request", "Bender");
	Form *pardon = randomIntern.makeForm("presidential pardon", "Gollum");
	Form *nope = randomIntern.makeForm("peace treaty", "Middle Earth");

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pardon << std::endl;

	std::cout << nope << std::endl;	

	return 0;
}