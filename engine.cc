#include "engine.h"
#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Engine::Engine(Board* theBoard, int numOpp, int bottomLine, int playerNum)
              : Player(theBoard, numOpp, bottomLine, playerNum) {
  pList = new Piece* [GRID_SIZE * GRID_SIZE];
  values = new int* [GRID_SIZE];
  for(int i = 0; i < GRID_SIZE; i++) {
    values[i] = new int [GRID_SIZE];
    for(int j = 0; j < GRID_SIZE; j++) {
      values[i][j] = 0;
    }
  }
}

void Engine::addPiece(Piece *p, int row, int col) {

}
void Engine::removePiece(int row, int col) {
  if (myPiece[row][col] != NULL) {
    for(int i = 0; i < numPiece; i++) {
      if (pList[i] == myPiece[row][col]) {
        pList[i] = NULL;
        for(int j = i; j < numPiece; j++) {
          pList[j] = pList[j + 1];
        }
        numPiece--;
        break;
      }
    }
    values[row][col] = 0;
    myPiece[row][col]->notifyNeighboursMoved();
    myPiece[row][col] = NULL;
  }
}
