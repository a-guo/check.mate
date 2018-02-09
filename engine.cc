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
  myPiece[row][col] = p;
  pList[numPiece] = p;
  numPiece++;
  if (p->getType() == 'K' || p->getType() == 'k') {
    theKing = p;
  }
  char type = p->getType();
  // negative == white; positive == black
  switch(type) {
  case 'P':
      values[row][col] = 1;
      break;
  case 'p':
      values[row][col] = 1;
      break;
  case 'N':
      values[row][col] = 2;
      break;
  case 'n':
      values[row][col] = 2;
      break;
  case 'B':
      values[row][col] = 3;
      break;
  case 'b':
      values[row][col] = 3;
      break;
  case 'R':
      values[row][col] = 3;
      break;
  case 'r':
      values[row][col] = 3;
      break;
  case 'Q':
      values[row][col] = 5;
      break;
  case 'q':
      values[row][col] = 5;
      break;
  case 'K':
      values[row][col] = 10;
      break;
  case 'k':
      values[row][col] = 10;
      break;
  default:
      break;
  }
  // check opponents
  for (int i = 0; i < numOpp; i++) {
    if (i != this->playerNum) {
      myPiece[row][col]->check(Opps[i]);
    }
  }
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
