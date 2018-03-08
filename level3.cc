#include "level3.h"
#include "player.h"
#include "piece.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Level3::Level3(Board* theBoard, int numOpp, int bottomLine, int playerNum)
              : Engine(theBoard, numOpp, bottomLine, playerNum) {}

bool Level3::move() {
  // defense
  for (int iRow = 0; iRow < GRID_SIZE; iRow++) {
    for (int iCol = 0; iCol < GRID_SIZE; iCol++) {
      if (getScore(iRow, iCol) > 0 && isChecked(iRow, iCol)) {
        // attack when being attacked
      }
    }
  }
}
