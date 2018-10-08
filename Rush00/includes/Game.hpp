#ifndef GAME_HPP
# define GAME_HPP

# include "Context.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Shots.hpp"

Context  *init(); 
int     game(Context *data);

#endif