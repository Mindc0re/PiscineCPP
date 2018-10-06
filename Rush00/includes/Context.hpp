#ifndef CONTEXT_HPP
# define CONTEXT_HPP

# include <ncurses.h>
# include <unistd.h>
# include <iostream>

class Context
{

public:
	Context();
	Context(Context const &inst);
	~Context();

	Context &		operator=(Context const &rhs);

	WINDOW 			*win;
	int				key;

};

#endif