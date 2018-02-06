#include "level1.h"
#include "player.h"
#include "piece.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Level1::Level1(Board* theBoard, int numOpp, int bottomLine, int playerNum);
bool Level1::move();
