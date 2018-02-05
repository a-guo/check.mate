#include "pawn.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Pawn::Pawn(char type, int row, int col, Player* p, Board* theBoard, int front)
        : Piece(type, row, col, p, theBoard), front(front), firstTime(true) {}

bool Pawn::validMove(int row, int col) {
  // THIS STILL NEEDS TO BE DONE!!!!!
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

void Pawn::notifyDisplay(Textdisplay& t) {
  t.notify(-1, -1, col, type);
}

void Pawn::upgrade() {
  char c;
  cin >> c;
  theBoard->setPiece(c, row, col);
}

int Pawn::getFront() {
  return front;
}
