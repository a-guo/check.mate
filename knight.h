#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"

class Knight : class Piece {
 public:
   Knight(char type, int row, int col, Player* p, Board* theBoard);
   bool validMove(int row, int col);
   bool tryNextMove();
   void check(Player* opp);
   void uncheck(Player* opp, int row, int col);
   void notifyDisplay(Textdisplay& t);
   void upgrade();
};

#endif
