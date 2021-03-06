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
        for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
          for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
            // if target & can attack, then attack
            if (abs(Opps[0]->getScore(fRow, fCol)) > 0 && Opps[0]->isChecked(fRow, fCol)) {
              for (int i = 0; i < numPiece; i++ ) {
                if (pList[i]->move(fRow, fCol)) {
                  myPiece[fRow][fCol] = myPiece[iRow][iCol];
                  myPiece[iRow][iCol] = NULL;
                  cout << "Computer moves " << (char)('a' + iCol) <<
                  GRID_SIZE - iRow << " " << (char)('a' + fCol) << GRID_SIZE - fRow << endl;
                  theBoard->notify(iRow, iCol, fRow, fCol);
                  return true;
                }
              }
            }
          }
        }
        // if no attack, then random
        for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
          for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
            // there could be an error here
            if (myPiece[iRow][fCol]->move(fRow, fCol)) {
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
    }
  }
  // if no need to defend, then try attacking
  for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
    for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
      // target exists and I can attack, then attack
      if (abs(Opps[0]->getScore(fRow, fCol)) > 0 && Opps[0]->isChecked(fRow, fCol)) {
        for (int i = 0; i < numPiece; i++) {
          if (pList[i]->move(fRow, fCol)) {
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
  }
  // if cannot attack, random move
  int i = rand() % numPiece;
  while (!pList[i]->tryNextMove()) {
    i = ( i + 1) % numPiece;
  }
  int iRow = pList[i]->getRow();
  int iCol = pList[i]->getCol();

  for (int fRow = 0; fRow < GRID_SIZE; fRow++) {
    for (int fCol = 0; fCol < GRID_SIZE; fCol++) {
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
  return true;
}
