#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <stdio.h>
#include <stdlib.h>

struct Gameboard
{
    Gameboard( void );
    int getIndex( int x, int y );
    char getFieldSymbol(int x, int y);
    void printGameboard( void );
    int getFirstEmptyInColumn( int column );
    void throwInColumn( int column, char symbol );

    char field[42];
};

#endif // GAMEBOARD_H
