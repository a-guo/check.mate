#include "level2.h"
#include "player.h"
#include "piece.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Level2::Level2(Board* theBoard, int numOpp, int bottomLine, int playerNum);
bool Level2::move();
