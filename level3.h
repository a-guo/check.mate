#ifndef LEVEL3_H
#define LEVEL3_H

#include "player.h"
#include "engine.h"

class Level3 : public Engine {
public:
  Level3(Board* theBoard, int numOpp, int bottomLine, int playerNum);
  bool move();
};
#endif
