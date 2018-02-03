#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : class Piece {
 public:
   Queen(char type, int row, int col, Player* p, Board* theBoard);
   bool validMove(int row, int col);
   bool tryNextMove();
   void check(Player* opp);
   void uncheck(Player* opp, int row, int col);
   void notifyDisplay(Textdisplay& t);
   void upgrade();
};

#endif
