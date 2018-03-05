#include "level1.h"
#include "player.h"
#include "piece.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Level1::Level1(Board* theBoard, int numOpp, int bottomLine, int playerNum)
              : Engine(theBoard, numOpp, bottomLine, playerNum) {}

bool Level1::move() {
  // randomly select a Piece
  bool done = false;
  int i = rand() % numPiece;
  while (!pList[i]->tryToMove()) {
    i = (i + 1) % numPiece;
  }
  int iRow = pList[i]->getRow();
  int iCol = pList[i]->getCol();

  for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
    for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
      if (myPiece[iRow][iCol]->move(fRow, fCol)) {
        theBoard->notify(iRow, iCol, fRow, fCol);
        myPiece[fRow][fCol] = myPiece[iRow][iCol];
        myPiece[iRow][iCol] = NULL;

        cout << "Computer moves " << (char)('a' + iCol) << GRID_SIZE - iRow
        << " " << (char)('a' + fCol) << GRID_SIZE - fRow << endl;

        return true;
      }
    }
  }
  return true;
}
