#include "gameboard.h"

Gameboard::Gameboard()
{
  for (int i=0; i<42; i++ )
  {
    field[i] = ' ';
  }
}

int Gameboard::getIndex(int x, int y)
{
  return y * 7 + x;
}

char Gameboard::getFieldSymbol(int x, int y)
{
  return (field[ getIndex(x,y) ] );
}

void Gameboard::printGameboard()
{
  system( "cls" );
  printf( "\r\n" );
  for( int y=5; y>=0; y-- )  // y-Richtung
  {
    printf( " " );
    for ( int x=0; x<7; x++ )  // x-Richtung
    {
      printf( "|%c", field[ getIndex( x, y ) ] );     // !!!!!
    }
    printf( "| \r\n" );
  }
  printf( "  0 1 2 3 4 5 6 \r\n " );
}

int Gameboard::getFirstEmptyInColumn(int column)
{
  int y = -1;
  do {
    y++;
  }while( field[ getIndex( column, y )] != ' '); //TODO: Was ist, wenn kein Feld frei ist?
  return y;
}

void Gameboard::throwInColumn(int column, char symbol)
{
  int y = getFirstEmptyInColumn( column );
  field[ getIndex( column,y ) ] = symbol;
}
