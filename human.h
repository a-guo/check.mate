#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
public:
  Human(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  void addPiece(Piece *p, int row, int col);
  void removePiece(int row, int col);
  bool move();
};
#endif
