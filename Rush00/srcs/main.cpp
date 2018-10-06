#include "../includes/Game.hpp"

int main(void) 
{

  Context *context = init();
  
  if(game(context) == 1)
    endwin();
  else
    return 0;
  
  return 0;    
}