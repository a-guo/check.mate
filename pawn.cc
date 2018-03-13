#include "pawn.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Pawn::Pawn(char type, int row, int col, Player* p, Board* theBoard, int front)
        : Piece(type, row, col, p, theBoard), front(front), firstTime(true) {}

bool Pawn::validMove(int row, int col) {
  bool result = false;
  // if move to same spot or outside of board boundaries
  if ((this->col == col && this->row == row) || (col > GRID_SIZE) || col < 0) {
    return false;
  }
  if ((this->col == col && this->row == row) || (row > GRID_SIZE) || row < 0) {
    return false;
  }
  // check en passant a valid move
  if (pawnJustMoved != NULL) {
    int pRow = pawnJustMoved->getRow();
    int pCol = pawnJustMoved->getCol();
    // -x-
    // Pp-
    // ---
    if ((pRow - front == row && pCol == col) &&
        (this->row + front == row && this->col + front == col)) {
      result = true;
    }
  }
  // check for capturing
  // -x-
  // P--
  if (theBoard->isPlaced(row, col) &&
      this->row + front == row && (this->col + 1 == col || this->col - 1 == col)) {
        result = true;
  }
  // if it's just moving forward one block, then it's good
  if (this->row + front == row && this->col == col) {
    if (theBoard->isPlaced(row, col)) return false;
    if (firstTime) {
      firstTime = false;
      pawnJustMoved = this;
    }
    result = true;
  }
  // check for first time movement - moving 2 blocks
  if (this->row + front * 2 == row && this->col == col && firstTime) {
    firstTime = false;
    // tell everyone that pawn just moved
    pawnJustMoved = this;
    result = true;
  }
  if(thePlayer->isPlaced(row, col)) return false;

  return result;
}

bool Pawn::tryNextMove() {
  return (validMove(row + front, col) ||
          validMove(row + front, col + front) ||
          validMove(row + front, col - front));
}

void Pawn::check(Player* opp) {
  if (row + front < GRID_SIZE && col + 1 < GRID_SIZE) {
    opp->check(row + front, col + 1);
  }
  if (row + front < GRID_SIZE && col - 1 > 0) {
    opp->check(row + front, col - 1);
  }
}

void Pawn::uncheck(Player *opp, int row, int col) {
  if (row + front < GRID_SIZE && col + 1 < GRID_SIZE) {
    opp->uncheck(row + front, col + 1);
  }
  if (row + front < GRID_SIZE && col - 1 > 0) {
    opp->uncheck(row + front, col - 1);
  }
}

void Pawn::notifyDisplay(TextDisplay& t) {
  t.notify(-1, -1, row, col, type);
}

void Pawn::upgrade() {
  char c;
  cin >> c;
  theBoard->setPiece(c, row, col);
}

int Pawn::getFront() {
  return front;
}
