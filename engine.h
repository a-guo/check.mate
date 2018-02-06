#ifndef ENGINE_H
#define ENGINE_H

#include "player.h"

class Engine : public Player {
protected:
  int** values;
  int numPiece;
  Piece** pList;
public:
  Engine(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  void addPiece(Piece *p, int row, int col);
  void removePiece(int row, int col);
  virtual bool move() = 0;
};
#endif
