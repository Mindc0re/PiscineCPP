#ifndef GAME_HPP
# define GAME_HPP

# include <unistd.h>
# include <ncurses.h>
# include "Context.hpp"
# include "AGameObject.hpp"
# include "Player.hpp"



Context  *init(); 
int     game(Context *data);

#endif