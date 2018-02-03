#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "textdisplay.h"

class Board;
class Player;

const int GRID_SIZE = 8;
const int MAX_NEIGHBOURS = 8;

class Piece {
protected:
  char type;
  int row, int col;
  int index;
  static Piece* pawnJustMoved;
  Player* thePlayer;
  Piece** neighbour;
  Board* theBoard;
  XWindow *w;
 public:
   Piece(char type, int row, int col, Player *p, Board *theBoard);
   // void setCoord(int row, int col);
   virtual bool validMove(int row, int col) = 0;
   virtual bool tryNextMove() = 0;
   virtual void check(Player* opp) = 0;
   virtual void uncheck(Player* opp, int row, int col) = 0;
   virtual void notifyDisplay(Textdisplay& t) = 0;

   bool move(int fRow, int fCol);
   bool notifyKing();
   void addNeightbours();
   void addNeightbours(Piece* neightbour);
   void notifyNeighboursMoved();
   void notifyNeighboursPlaced();
   void notify(Player *opp, int row, int col);

   virtual void upgrade() = 0;

   int getRow();
   int getCol();
   char getType();

   ~Piece() virtual;
};

#endif
