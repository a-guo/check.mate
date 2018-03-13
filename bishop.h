#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
 public:
   Bishop(char type, int row, int col, Player* p, Board* theBoard);
   bool validMove(int row, int col);
   bool tryNextMove();
   void check(Player* opp);
   void uncheck(Player* opp, int row, int col);
   void notifyDisplay(TextDisplay& t);
   void upgrade();
};

#endif
