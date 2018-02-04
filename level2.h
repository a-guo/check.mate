#ifndef LEVEL2_H
#define LEVEL2_H

#include "player.h"
#include "engine.h"

class Level2 : public Engine {
public:
  Level2(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  bool move();
};
#endif
