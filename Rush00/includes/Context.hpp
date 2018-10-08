#ifndef CONTEXT_HPP
# define CONTEXT_HPP

# define MAX_ENEMY 5
# define MAX_SHOTS 400

# include <ncurses.h>
# include <unistd.h>
# include <iostream>
# include <fstream>
# include <sys/time.h>
# include <vector>

class Context
{

public:
	Context();
	Context(Context const &inst);
	~Context();

	Context &			operator=(Context const &rhs);

	WINDOW 				*win;
	int					key;
	struct				timeval	_start;
	struct				timeval _end;

};

#endif