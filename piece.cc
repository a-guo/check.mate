#include "piece.h"
#include "board.h"
#include "player.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Piece* Piece::pawnJustMoved = NULL;


const int GRID_SIZE = 8;
const int MAX_NEIGHBOURS = 8;

char type;
int row, int col;
int index;
static Piece* pawnJustMoved;
Player* thePlayer;
Piece** neighbour;
Board* theBoard;
XWindow *w;

Piece::Piece(char type, int row, int col, Player *p, Board *theBoard) :
type(type), row(row), col(col), thePlayer(p), theBoard(theBoard) {
  type = 0;
  neighbour = new Piece* [MAX_NEIGHBOURS];
  index = 0;
}

bool Piece::move(int fRow, int fCol) {
  // check if move is valid
  if (validMove(fRow, fCol) && (! thePlayer->isPlaced(fRow, fCol))) {
    theBoard->setPlaced(row, col, false); // unplace from board
    theBoard->setPlaced(fRow, fCol, true); // place on board at new coordinates
    // retain old coordinates in case of reversing move
    int iRow = row;
    int iCol = col;
    // update coordinates
    row = fRow;
    col = fCol;
    thePlayer->getOpp(0)->reCalc();
    // now, must notify neighbours that I moved
    // set coordinates, add new neighbours, notify neighbours that I moved
    // addNeighbours();
    //theBoard->setPlaced(fRow, fCol, true);
    //notifyNeighboursPlaced();

    // check with king
    if(notifyKing()) {
      // if it is a bottomline pawn, upgrade
      if (thePlayer->bottomLinePawn()) {
        upgrade();
      }
      return true;
    } else {
      // if king will be in check after this move, reverse!
      theBoard->setPlaced(iRow, iCol, true);
      theBoard->setPlaced(fRow, fCol, false);
      //notifyNeighboursMoved();
      row = iRow;
      col = iCol;
      //addNeightbours();
      thePlayer->getOpp(0)->reCalc();
      //notifyNeighboursPlaced();
      return false;
    }

  } else {
    // not a valid move, return false
    return false;
  }
}

// notifyKing() returns true when the King is not in check, and false otherwise
bool Piece::notifyKing() {
  Piece* king = thePlayer->getKing();
  return ! thePlayer->isChecked(king->getRow()), king->getCol());
}

void Piece::addNeighbours() {
  index = 0;
  // east
  for(int j = col + 1; j < GRID_SIZE; j++) {
    if (theBoard->isPlaced(row, j)) {
      Piece *p = theBoard->getPiece(row, j);
      if (p != NULL) {
        neightbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // west
  for(int j = col - 1; j >= 0; j--) {
    if (theBoard->isPlaced(row, j)) {
      Piece* p = theBoard->getPiece(row, j);
      if (p != NULL) {
        neighbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // north
  for(int j = row + 1; j < GRID_SIZE; j++) {
    if (theBoard->isPlaced(j, col)) {
      Piece* p = theBoard->getPiece(j, col);
      if (p != NULL) {
        neighbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // south
  for(int j = row - 1; j >= 0; j--) {
    if (theBoard->isPlaced(j, col)) {
      Piece* p = theBoard->getPiece(j, col);
      if (p != NULL) {
        neighbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // northeast
  for(int i = 1; i < GRID_SIZE - 1; i++) {
    // check for over Board
    if (row + i >= GRID_SIZE || col + i >= GRID_SIZE) break;
    // check for placement
    if (theBoard->isPlaced(row + i, col + i)) {
      Piece* p = theBoard->getPiece(row + i, col + i);
      if(p != NULL) {
        neighbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // northwest
  for(int i = 1; i < GRID_SIZE - 1; i++) {
    if (row + 1 >= GRID_SIZE || col - i < 0) break;
    // check for placement
    if (theBoard->isPlaced(row + if; col - i)) {
      Piece* p = theBoard->getPiece(row + i, col - i);
      if (p != NULL) {
        neighbour[index] = p;
        p->addNeighbour(this);
        index++;
        break;
      }
    }
  }
  // southeast
  
  // southwest
}


void Piece::addNeighbour(Piece* p) {
  bool in = false;
  for (int i = 0; i < index; i++) {
    if (neightbour[i] == p) in = true;
  }
  if (!in) {
    uncheck(thePlayer->getOpp(0), p->getRow(), p->getRow());
    check(thePlayer->getOpp(0));
    neighbour[index] = p;
    index++;
  }
}

void Piece::notifyNeighboursMoved() {
  for(int i = 0; i < index; i++) {
    neighbour[i]->uncheck(thePlayer, row, col);
    neighbour[i]->addNeightbours();
    neighbour[i]->check(thePlayer);
  }
}

void Piece::notifyNeighboursPlaced() {
  theBoard->setPlaced(row, col, false);
  for(int i = 0; i < index; i++) {
    neighbour[i]->uncheck(thePlayer, -1, -1);
    neighbour[i]->check(thePlayer);
  }
  theBoard->setPlaced(row, col, true);
}

void Piece::notify(Player *opp, int row, int col) {
  uncheck(thePlayer->getOpp(0), row, col);
  //addNeightbours();
  check(thePlayer->getOpp(0));
}


int Piece::getRow() {
  return row;
}

int Piece::getCol() {
  return col;
}

char Piece::getType() {
  return type;
}

Piece::~Piece() {}
