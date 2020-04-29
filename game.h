#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "gameboard.h"
#include "player.h"

struct Game
{
    Game( void );
    void printGameboard( void );
    bool isValidMove( int column );
    void play( void );
    bool isGameboardFull( void );
    bool isGameWon( void );

    Gameboard gameboard;
    Player    player[2];
};

#endif // GAME_H
