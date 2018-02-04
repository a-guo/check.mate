#ifndef LEVEL4_H
#define LEVEL4_H

#include "player.h"
#include "engine.h"

class Level4 : public Engine {
public:
  Level4(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  bool move();
};
#endif
