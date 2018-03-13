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
  else if (row > this->row && col < this->col) {
    for (int i = 1; i < row - this->row; i++) {
      if (theBoard->isPlaced(this->row + i, this->col - i)) return false;
    }
  }
  // down + right
  else if (row < this->row && col > this->col) {
    for (int i = 1; i < this->row - row; i++) {
      if (theBoard->isPlaced(this->row - i, this->col + i)) return false;
    }
  }
  // down + left
  else if (row < this->row && col < this->col) {
    for (int i = 1; i < this->row - row; i++) {
      if (theBoard->isPlaced(this->row - i, this->col - i)) return false;
    }
  }
  return true;
}

bool Queen::tryNextMove() {
  // right
  for (int i = col + 1; i < GRID_SIZE; i++) {
    if (validMove(row, i)) return true;
  }
  // <---R
  for (int i = col - 1; i >= 0; i--) {
    if (validMove(row, i)) return true;
  }
  // R up
  for (int i = row + 1; i < GRID_SIZE; i++) {
    if (validMove(i, col)) return true;
  }
  // R down
  for (int i = row - 1; i >= 0; i--) {
    if (validMove(i, col)) return true;
  }

  for (int i = 1; i < GRID_SIZE; i++) {
    // check overbounds
    if (this->row + i >= GRID_SIZE || this->col + i >= GRID_SIZE) break;
    // check placement
    if (thePlayer->isPlaced(row + i, col + i)) break;
    if (validMove(row + i, col + i)) return true;
  }
  // upper left
  for (int i = 1; i < GRID_SIZE; i++) {
    if (this->row + i >= GRID_SIZE || this->col - i >= GRID_SIZE) break;
    if (thePlayer->isPlaced(row + i, col - i)) break;
    if (validMove(row + i, col - i)) return true;
  }
  for (int i = 1; i < GRID_SIZE; i++) {
    if (this->row - i >= GRID_SIZE || this->col + i >= GRID_SIZE) break;
    if (thePlayer->isPlaced(row - i, col + i)) break;
    if (validMove(row - i, col + i)) return true;
  }
  for (int i = 1; i < GRID_SIZE; i++) {
    if (this->row - i >= GRID_SIZE || this->col - i >= GRID_SIZE) break;
    if (thePlayer->isPlaced(row - i, col - i)) break;
    if (validMove(row - i, col - i)) return true;
  }
  return false;
}

void Queen::check(Player* opp) {
  // right
  for (int i = col + 1; i < GRID_SIZE; i++) {
    if (theBoard->isPlaced(row, i)) {
      opp->check(row, i);
      break;
    }
    opp->check(row, i);
  }
  // <-- R
  for (int i = col - 1; i >= 0; i--) {
    if (theBoard->isPlaced(row, i)) {
      opp->check(row, i);
      break;
    }
    opp->check(row, i);
  }
  // R up
  for (int i = row + 1; i < GRID_SIZE; i++) {
    if (theBoard->isPlaced(i, col)) {
      opp->check(i, col);
      break;
    }
    opp->check(i, col);
  }
  // R down
  for (int i = row - 1; i >= 0; i--) {
    if (theBoard->isPlaced(i, col)) {
      opp->check(i, col);
      break;
    }
    opp->check(i, col);
  }
  // up right
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row + i > GRID_SIZE || col + i > GRID_SIZE) break;
    if (theBoard->isPlaced(row + i, col+ i)) {
      opp->check(row + i, col + i);
      break;
    }
    opp->check(row + i, col + i);
  }
  // up left
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row + i > GRID_SIZE || col - i < 0) break;
    if (theBoard->isPlaced(row + i, col - i)) {
      opp->check(row + i, col - i);
      break;
    }
    opp->check(row + i, col - i);
  }
  // down right
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row - i < 0 || col + i > GRID_SIZE) break;
    if (theBoard->isPlaced(row - i, col + i)) {
      opp->check(row - i, col + i);
      break;
    }
    opp->check(row - i, col + i);
  }
  // down left
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row - i < 0 || col - i < 0) break;
    if (theBoard->isPlaced(row - i, col - i)) {
      opp->check(row - i, col - i);
      break;
    }
    opp->check(row - i, col - i);
  }
}

void Queen::uncheck(Player* opp, int row, int col) {
  // right
  for (int i = col + 1; i < GRID_SIZE; i++) {
    if (theBoard->isPlaced(row, i)) {
      opp->uncheck(row, i);
      break;
    }
    opp->uncheck(row, i);
  }
  // <-- R
  for (int i = col - 1; i >= 0; i--) {
    if (theBoard->isPlaced(row, i)) {
      opp->uncheck(row, i);
      break;
    }
    opp->uncheck(row, i);
  }
  // R up
  for (int i = row + 1; i < GRID_SIZE; i++) {
    if (theBoard->isPlaced(i, col)) {
      opp->uncheck(i, col);
      break;
    }
    opp->uncheck(i, col);
  }
  // R down
  for (int i = row - 1; i >= 0; i--) {
    if (theBoard->isPlaced(i, col)) {
      opp->uncheck(i, col);
      break;
    }
    opp->uncheck(i, col);
  }
  // up right
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row + i > GRID_SIZE || col + i > GRID_SIZE) break;
    if (theBoard->isPlaced(row + i, col+ i)) {
      opp->uncheck(row + i, col + i);
      break;
    }
    opp->uncheck(row + i, col + i);
  }
  // up left
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row + i > GRID_SIZE || col - i < 0) break;
    if (theBoard->isPlaced(row + i, col - i)) {
      opp->uncheck(row + i, col - i);
      break;
    }
    opp->uncheck(row + i, col - i);
  }
  // down right
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row - i < 0 || col + i > GRID_SIZE) break;
    if (theBoard->isPlaced(row - i, col + i)) {
      opp->uncheck(row - i, col + i);
      break;
    }
    opp->uncheck(row - i, col + i);
  }
  // down left
  for (int i = 0; i < GRID_SIZE; i++) {
    if (row - i < 0 || col - i < 0) break;
    if (theBoard->isPlaced(row - i, col - i)) {
      opp->uncheck(row - i, col - i);
      break;
    }
    opp->uncheck(row - i, col - i);
  }
}

void Queen::notifyDisplay(TextDisplay& t) {}
void Queen::upgrade() {}
