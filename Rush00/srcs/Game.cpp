#include "../includes/Game.hpp"

Context *init()
{
    Context *game = new Context();
    
    return game;
}

int     game(Context *data)
{
    int key = 0;
    AGameObject *player = new Player();
    player->appearOnScreen(data);
    while (1) 
    {
        werase(data->win); 
        player->move(data, 1);
        key = getch();
          if(key == 27)
            return 1;
        mvwprintw(data->win, 0, 0, "%d", key);
        wrefresh(data->win);
        usleep(10000);
    }
    return 1;
}