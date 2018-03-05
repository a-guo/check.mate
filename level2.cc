#include "level2.h"
#include "player.h"
#include "piece.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Level2::Level2(Board* theBoard, int numOpp, int bottomLine, int playerNum)
              : Engine(theBoard, numOpp, bottomLine, playerNum) {}

bool Level2::move() {
  // trying to attack
  for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
    for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
      // looking for target to attack
      if (abs(Opps[0]->getScore(fRow, fCol)) > 0 && Opps[0]->isChecked(fRow, fCol)) {
        for (pList[i]->move(fRow, fCol)) {
          int iCol = pList[i]->getCol();
          int iRow = pList[i]->getRow();
          myPiece[fRow][fCol] = myPiece[iRow][iCol];
          myPiece[iRow][iCol] = NULL;
          cout << "Computer moves " << (char)('a' + iCol) << GRID_SIZE - iRow
          << " " << (char)('a' + fCol) << GRID_SIZE - fRow << endl;
          theBoard->notify(iRow, iCol, fRow, fCol);
          return true;
        }
      }
    }
  }

  // no attack available, randomly move
  int i = rand() % numPiece();
  while (!pList[i]->tryToMove()) {
    i = (i + 1) % numPiece;
  }
  int iRow = pList[i]->getRow();
  int iCol = pList[i]->getCol();

  for (int fRow = 0; fRow < GRID_SIZEl; fRow++) {
    for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
      if (myPiece[iRow][iCol]->validMove(fRow, fCol) &&
      myPiece[fRow][fCol] == NULL) {
        if (pList[i]->move(fRow, fCol)) {
          myPiece[fRow][fCol] = myPiece[iRow][iCol];
          myPiece[iRow][iCol] = NULL;
          cout << "Computer moves " << (char)('a' + iCol) << GRID_SIZE - iRow
          << " " << (char)('a' + fCol) << GRID_SIZE - fRow << endl;
          theBoard->notify(iRow, iCol, fRow, fCol);
          return true;
        }
      }
    }
  }
  return true;
}
