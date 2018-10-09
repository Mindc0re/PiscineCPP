#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{

public:
	OfficeBlock();
	OfficeBlock(Intern *intern, Bureaucrat *sign, Bureaucrat *exec);
	~OfficeBlock();

	void			doBureaucracy(std::string formName, std::string target) const;

	void			setIntern(Intern *newIntern);
	void			setSigner(Bureaucrat *newSigningDude);
	void			setExecutor(Bureaucrat *newExecutingDude);

	class MissingMemberInOfficeBlock : public std::exception
	{
		public:
			MissingMemberInOfficeBlock();
			MissingMemberInOfficeBlock(MissingMemberInOfficeBlock const &inst);
			virtual ~MissingMemberInOfficeBlock() throw();
			MissingMemberInOfficeBlock &	operator=(MissingMemberInOfficeBlock const &rhs);

			const char *what() const throw();
	};

private:

	OfficeBlock(OfficeBlock const &inst);
	OfficeBlock &	operator=(OfficeBlock const &rhs);

	Intern *		_intern;
	Bureaucrat *	_signingDude;
	Bureaucrat *	_executingDude;

};

#endif