#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : class Piece {
  int front;
  bool firstTime;
 public:
   Pawn(char type, int row, int col, Player* p, Board* theBoard, int front);
   bool validMove(int row, int col);
   bool tryNextMove();
   void check(Player* opp);
   void uncheck(Player *opp, int row, int col);
   void notifyDisplay(TextDisplay& t);

   void upgrade();
   int getFront();

};

#endif
