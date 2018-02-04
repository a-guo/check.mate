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

}

bool Piece::notifyKing() {
  Piece* king = thePlayer->getKing();
  return ! thePlayer->isChecked(king->getRow()), king->getCol());
}

void Piece::addNeightbours() {
  
}

void Piece::addNeightbour(Piece* p) {
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
