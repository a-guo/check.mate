#include "queen.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Queen::Queen(char type, int row, int col, Player* p, Board* theBoard)
            : Piece(type, row, col, p, theBoard) {}

bool Queen::validMove(int row, int col) {
  if ((this->col == col && this->row == row) || (col + 1 > GRID_SIZE) || col < 0) {
    return false;
  }
  if ((this->col == col && this->row == row) || (row + 1 > GRID_SIZE) || row < 0) {
    return false;
  }
  // moving like a rook
  // R--->
  if (row > this->row && this->col == col) {
    for (int i = this->row + 1; i < row - 1; i++) {
      if (theBoard->isPlaced(i, this->col)) return false;
    }
  }
  // up
  else if (row < this->row && this->col == col) {
    for (int i = this->row - 1; i > row - 1; i--) {
      if (theBoard->isPlaced(i, this->col)) return false;
    }
  }
  // R up
  else if (col > this->col && this->row == row) {
    for (int i = this->col + 1; i < col - 1; i++) {
      if (theBoard->isPlaced(this->row, i)) return false;
    }
  }
  // R down
  else if (col < this->col && this->row == row) {
    for (int i = this->col - 1; i > col - 1; i--) {
      if (theBoard->isPlaced(this->row, i)) return false;
    }
  }
  else if (row > this->row && col > this->col) {
    for (int i = 1; i < row - this->row; i++) {
      if (theBoard->isPlaced(this->row + 1, this->col + i)) return false;
    }
  }
  // up + left
}

bool Queen::tryNextMove();
void Queen::check(Player* opp);
void Queen::uncheck(Player* opp, int row, int col);

void Queen::notifyDisplay(Textdisplay& t) {}
void Queen::upgrade() {}
