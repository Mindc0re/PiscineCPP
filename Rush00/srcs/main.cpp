#include "../includes/Game.hpp"

int main(void) 
{
  srand(time(NULL));

  Context *context = init();
  
  if(game(context) == 1)
    endwin();
  else
    return 0;
  
  delete(context);
  
  return 0;    
}