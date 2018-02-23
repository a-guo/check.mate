#ifndef KING_H
#define KING_H

#include "piece.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"

class King : class Piece {
 public:
   King(char type, int row, int col, Player* p, Board* theBoard);
   bool validMove(int row, int col);
   bool tryNextMove();
   void check(Player* p);
   void uncheck(Player* p, int row, int col);
   void notifyDisplay(Textdisplay& t);
   void upgrade();

   void castling();
};



#endif
