#include "Context.hpp"

/*
	Constructors and destructors
*/

Context::Context()
{
	win = initscr();
	key = 0;

	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	std::cout << "Log : Context was created successfully" << std::endl;
}

Context::Context(Context const &inst)
{
	*this = inst;
}

Context::~Context()
{
	// TODO : Code d'exit de ncurses et destruction de GameObjects si nécéssaire.
}


/*
	Operator overloads
*/

Context &		Context::operator=(Context const &rhs)
{
	win = rhs.win;
	key = rhs.key;

	return *this;
}