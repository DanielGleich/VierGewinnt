#include "game.h"

Game::Game()
{
  player[0].symbol = 'X';
  player[1].symbol = 'O';
  printf( "Gib den Namen des Spielers 1 an: " );
  scanf( "%s", player[0].name );
  printf( "Gib den Namen des Spielers 2 an: " );
  scanf( "%s", player[1].name );
}

void Game::printGameboard()
{
  gameboard.printGameboard();
}

bool Game::isValidMove(int column)
{
  if ( (column>=0 )
       && (column<=6)
       && ( gameboard.getFieldSymbol(column, 5) ==' ' ) )return (true);
  else return false;
}

void Game::play()
{
  int column;
  Player *activePlayer = &player[0];

  do
  {
    if ( activePlayer == &player[0] ) activePlayer = &player[1];
    else activePlayer = &player[0];
    printGameboard();
    do
    {
      printf( "%s: ", activePlayer->name );
      scanf( "%d", &column );
    } while (isValidMove(column)==false);
    gameboard.throwInColumn( column, activePlayer->symbol );
  } while( !isGameboardFull() && !isGameWon() );
  printGameboard();
}

bool Game::isGameboardFull()
{
  for ( int i = 0; i < 42; i++ )
  {
    if ( gameboard.field[i]==' ' ) return false;
  }
  return true;
}

bool Game::isGameWon()
{
  // 4 in einer Zeile
  int counter = 1;
  for ( int y=0; y<6; y++ )
  {
    for ( int x=1; x<7; x++ )
    {
      if ( gameboard.getFieldSymbol( x-1, y ) ==gameboard.getFieldSymbol( x, y )
           && gameboard.getFieldSymbol( x, y )!=' ' )
        counter++;
      else
        counter = 1;
      if ( counter>=4 ) return true;
    }
  }

  // 4 in einer Spalte
  counter = 1;
  for ( int x=0; x<7; x++ )
  {
    for ( int y=1; y<6; y++ )
    {
      if ( gameboard.getFieldSymbol( x, y-1 ) == gameboard.getFieldSymbol( x, y )
           && gameboard.getFieldSymbol( x, y ) != ' ' )
        counter++;
      else
        counter = 1;
      if ( counter>=4 ) return true;
    }
  }

  // 4 in der Diagonalen links oben nach rechts unten
  for ( int x=0; x<4; x++ )
  {
    for ( int y=0; y<3; y++ )
    {
      if (    gameboard.getFieldSymbol( x,   y )   == gameboard.getFieldSymbol( x+1, y+1 )
           && gameboard.getFieldSymbol( x+1, y+1 ) == gameboard.getFieldSymbol( x+2, y+2 )
           && gameboard.getFieldSymbol( x+2, y+2 ) == gameboard.getFieldSymbol( x+3, y+3 )
           && gameboard.getFieldSymbol( x,   y )   != ' ' )
        return true;
    }
  }

  // 4 in der Diagonalen von links unten nach rechts oben
  for ( int x=6; x>2; x-- )
  {
    for ( int y=0; y<3; y++ )
    {
      if (    gameboard.getFieldSymbol( x,   y )   == gameboard.getFieldSymbol( x-1, y+1 )
           && gameboard.getFieldSymbol( x-1, y+1 ) == gameboard.getFieldSymbol( x-2, y+2 )
           && gameboard.getFieldSymbol( x-2, y+2 ) == gameboard.getFieldSymbol( x-3, y+3 )
           && gameboard.getFieldSymbol( x,   y )   != ' ' )
        return true;
    }
  }


  return false;
}
