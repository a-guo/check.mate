#ifndef LEVEL1_H
#define LEVEL1_H

#include "player.h"
#include "engine.h"

class Level1 : public Engine {
public:
  Level1(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  bool move();
};
#endif
