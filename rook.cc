#include "rook.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Rook::Rook(char type, int row, int col, Player* p, Board* theBoard)
          : Piece(type, row, col, p, theBoard), moved(false) {}

bool Rook::validMove(int row, int col) {

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
