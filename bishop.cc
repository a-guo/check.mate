#include "bishop.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(char type, int row, int col, Player* p, Board* theBoard)
              : Piece(type, row, col, p, theBoard) {}

bool Bishop::validMove(int row, int col) {
  // check if col or row out of bounds, or no movement
  if ((this->row == row && this->col == col) || (col + 1 > GRID_SIZE) || col < 0) {
    return false;
  }
  if ((this->row == row && this->col == col) || (row + 1 > GRID_SIZE) || row < 0) {
    return false;
  }
  // check for diagonal movement
  if (!(this->row - row == this->col - col)) {
    return false;
  }
  // check for blocking
  // northeast
  if (row > this->row && col > this->col) {
    for (int i = 1; i < row - this->row; i++) {
      if (theBoard->isPlaced(this->row + i, this->col + i)) {
        return false;
      }
    }
  }
  // northwest
  else if (row > this->row && col < this->col) {
    for (int i = 1; i < row - this->row; i++) {
      if (theBoard->isPlaced(this->row + i; this->col - i)) {
        return false;
      }
    }
  }
  // southeast
  else if (row < this->row && col > this->col) {
    for (int i = 1; i < this->row - row; i++) {
      if (theBoard->isPlaced(this->row - i, this->col + i)) {
        return false;
      }
    }
  }
  // down left
  else if (row < this->row && col < this->col) {
    for (int i = 1; i < this->row - row; i++) {
      if (theBoard->isPlaced(this->row - i, this->col - i)) {
        return false;
      }
    }
  }
  return true;
}

bool Bishop::tryNextMove() {
  // northeast
  for (int i = 1; i < GRID_SIZE; i++) {
    // check going overboard
    if (this->row + i >= GRID_SIZE || this->col + i >= GRID_SIZE) {
      break;
    }
    // check already placed
    if (thePlayer->isPlaced(this->row + i, this->col + i)) {
      break;
    }
    // check validity
    if (validMove(row + i, col + i)) {
      return true;
    }
  }
  // northwest
  for (int i = 1; i < GRID_SIZE; i++) {
    if (row + i >= GRID_SIZE || col - i < 0) break;
    if (thePlayer->isPlaced(row + i, col - i)) break;
    if (validMove(row + i, col - i)) return true;
  }
  // southeast
  for (int i = 1; i < GRID_SIZE; i++) {
    if (row - i < 0 || col + i >= GRID_SIZE) break;
    if (thePlayer->isPlaced(row - i, col + i)) break;
    if (validMove(row - i, col + i)) return true;
  }
  // southwest
  for (int i = 1; i < GRID_SIZE; i++) {
    if (row - i < 0 || col - i < 0) break;
    if (thePlayer->isPlaced(row - i, col - i)) break;
    if (validMove(row - i, col - i)) return true;
  }
  return false;
}

void Bishop::check(Player* opp);
void Bishop::uncheck(Player* opp, int row, int col);

void Bishop::notifyDisplay(TextDisplay& t) {}

void Bishop::upgrade() {}
