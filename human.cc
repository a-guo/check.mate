#include "human.h"
#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Human::Human(Board* theBoard, int numOpp, int bottomLine, int playerNum)
            : Player(theBoard, numOpp, bottomLine, playerNum) {}

void Human::addPiece(Piece *p, int row, int col) {

}

void Human::removePiece(int row, int col) {
  if (myPiece[row][col] != NULL) {
    myPiece[row][col]->notifyNeighboursMoved();
    myPiece[row][col] = NULL;
    values[row][col] = 0;
  }
}

bool Human::move() {
  char iColC;
  int iRow;
  char fColC;
  int fRow;

  cin >> iColC >> iRow;
  cin >> fColC >> fRow;

  int iCol = iColC - 'a';
  int fCol = fColC - 'a';

  iRow = GRID_SIZE - iRow;
  fRow = GRID_SIZE - fRow;

  if(myPiece[iRow][iCol] == NULL) return false;
  if(myPiece[iRow][iCol]->move(fRow, fCol)) {
    myPiece[fRow][fCol] = myPiece[iRow][iCol];
    myPiece[iRow][iCol] = NULL;
    theBoard->notify(iRow, iCol, fRow, fCol);
    return true;
  }
}
