#include "../includes/Game.hpp"

Context *init()
{
    Context *game = new Context();

    Enemy::enemyArr.reserve(MAX_ENEMY);
    for (int i = 0 ; i < MAX_ENEMY ; i++)
    {
        Enemy *enemy = new Enemy();
        Enemy::enemyArr.push_back(enemy);
        Enemy::enemyArr[i]->appearOnScreen(game);
    }

    Shots::shotsArr.reserve(MAX_SHOTS);
    for (int j = 0 ; j < MAX_SHOTS ; j++)
    {
        Shots *shot = new Shots();
        Shots::shotsArr.push_back(shot);
    }

    return game;
}

void    moveEnemies(Context *data)
{
    for (int i = 0 ; i < MAX_ENEMY ; i++)
    {
        Enemy::enemyArr[i]->move(data, -1, 0);
    }
}

void    moveShots(Context *data)
{
    for (int i = 0 ; i < MAX_SHOTS ; i++)
    {
        Shots::shotsArr[i]->move(data, 1, 0);
    }
}

void    shoot(Context *data, Coordinates pos)
{
    for (int i = 0 ; i < MAX_SHOTS ; i++)
    {
        if (Shots::shotsArr[i]->isOnScreen() == false)
            Shots::shotsArr[i]->appearInFront(data, pos);
    }
}

void    deleteEnemies()
{
    for (int i = 0 ; i < MAX_ENEMY ; i++)
        delete(Enemy::enemyArr[i]);
}

void    deleteShots()
{
    for (int i = 0 ; i < MAX_SHOTS ; i++)
        delete(Shots::shotsArr[i]);
}

int     game(Context *data)
{
    int key = 0;
    int useconds;
    bool continueGame = true;

    AGameObject *player = new Player();
    player->appearOnScreen(data);
    cbreak();
    noecho();
    curs_set(0);
    while (continueGame)
    {
        gettimeofday(&data->_start, NULL);        
        key = getch();
        
        if(key == 27)
            return 1;
        if(key == KEY_RIGHT)
            player->move(data, 1, 0);
        if(key == KEY_LEFT)
            player->move(data, -1, 0);
        if(key == KEY_DOWN)
            player->move(data, 0, 1);
        if(key == KEY_UP)
           player->move(data, 0, -1);
        if (key == 32)
            shoot(data, player->getCoordinates());
        
        wrefresh(data->win);
        werase(data->win);
        gettimeofday(&data->_end, NULL);
        
        useconds = 10000 - (data->_end.tv_usec - data->_start.tv_usec);
        if(useconds >= 10000)
            useconds = 1; 
        if(useconds <= 0)
            useconds = 1;
        
        player->move(data, 0, 0);
        moveEnemies(data);
        moveShots(data);
        
        if (player->isOnScreen() == false)
            continueGame = false;

        usleep(useconds);
    }

    delete(player);
    deleteEnemies();
    deleteShots();

    return 1;
}
