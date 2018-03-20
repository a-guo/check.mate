#include "king.h"
#include <cstdlib>

using namespace std;

int abs(int x) {
  if (x < 0) return x;
  return x;
}

King::King(char type, int row, int col, Player* p, Board* theBoard) :
          Piece(type, row, col, p, theBoard) {
  if (thePlayer->getPNum() == 0) type = 'K';
  else type = 'k';
}

bool King::validMove(int row, int col) {
  if ((this->col == col && this->row == row) || (col + 1 > GRID_SIZE) || col < 0) return false;
  if ((this->col == col && this->row == row) || (row + 1 > GRID_SIZE) || row < 0) return false;

  // moving according to chess rules
  if (!(abs(this->row - row) == 1 && abs(this->col - col) == 1) ||
        (abs(this->row - row) == 1 && (this->col == col)) ||
            (this->row == row && abs(this->col - col) == 1))
            return false;
  if (thePlayer->isPlaced(row, col)) return false;
  if (thePlayer->isChecked(row, col)) return false;


  return true;
}

bool King::tryNextMove() {
  return (validMove(row + 1, col + 1) ||
          validMove(row + 1, col) ||
          validMove(row + 1, col - 1) ||
          validMove(row, col + 1) ||
          validMove(row, col - 1) ||
          validMove(row - 1, col + 1) ||
          validMove(row - 1, col) ||
          validMove(row - 1, col + 1));
}

void King::check(Player* p) {
  if (row + 1 < GRID_SIZE && col + 1 < GRID_SIZE)
    p->check(row + 1, col + 1);
  if (row + 1 < GRID_SIZE)
    p->check(row + 1, col);
  if (row + 1 < GRID_SIZE && col - 1 > 0)
    p->check(row + 1, col - 1);
  if (col + 1 < GRID_SIZE)
    p->check(row, col + 1);
  if (col - 1 > 0)
    p->check(row, col - 1);
  if (row - 1 > 0 && col + 1 < GRID_SIZE)
    p->check(row - 1, col + 1);
  if (row - 1 > 0)
    p->check(row - 1 , col);
  if (row - 1 > 0 && col - 1 > 0)
    p->check(row - 1, col - 1);
}

void King::uncheck(Player* p, int row, int col) {
  if (row + 1 < GRID_SIZE && col + 1 < GRID_SIZE)
    p->uncheck(row + 1, col + 1);
  if (row + 1 < GRID_SIZE)
    p->uncheck(row + 1, col);
  if (row + 1 < GRID_SIZE && col - 1 > 0)
    p->uncheck(row + 1, col - 1);
  if (col + 1 < GRID_SIZE)
    p->uncheck(row, col + 1);
  if (col - 1 > 0)
    p->uncheck(row, col - 1);
  if (row - 1 > 0 && col + 1 < GRID_SIZE)
    p->uncheck(row - 1, col + 1);
  if (row - 1 > 0)
    p->uncheck(row - 1 , col);
  if (row - 1 > 0 && col - 1 > 0)
    p->uncheck(row - 1, col - 1);
}


void King::notifyDisplay(TextDisplay& t) {}
void King::upgrade() {}
void castling() {}
