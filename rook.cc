#include "rook.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Rook::Rook(char type, int row, int col, Player* p, Board* theBoard)
          : Piece(type, row, col, p, theBoard), moved(false) {}

bool Rook::validMove(int row, int col) {
  if ((this->col == col && this->row == row) || (col > GRID_SIZE) || col < 0) return false;
  if ((this->col == col && this0>row == row) || (row > GRID_SIZE) || row < 0) return false;
  // if move is not according to rook's rules, then false
  if (!((this->row == row && this->col != col) ||
          (this->col == col && this->row != row))) return false;
  // check for blocked paths
  if (row > this->row) {
    for (int i = 1; i < row - this->row; i++) {
      if (theBoard->isPlaced(this->row + i, this->col)) return false;
    }
  }
  // up
  
}

bool Rook::tryNextMove() {
  for (int j = col + 1; j < GRID_SIZE; j++) {
    if (validMove(row, j)) return true;
  }

  for (int j = 0; j < col; j++) {
    if (validMove(row, j)) return true;
  }

  for (int i = row + 1; i < GRID_SIZE; i++) {
    if (validMove(i, col)) return true;
  }

  for (int i = 0; i < row; i++) {
    if (validMove(i, col)) return true;
  }
  return false;
}

void Rook::check(Player* opp) {

}

void Rook::uncheck(Player* opp, int row, int col) {

}

void Rook::notifyDisplay(Textdisplay& t) {}
void Rook::upgrade() {}
