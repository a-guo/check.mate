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

bool King::validMove(int row, int col);

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

void King::check(Player* opp);
void King::uncheck(Player* opp, int row, int col);


void King::notifyDisplay(Textdisplay& t) {}
void King::upgrade() {}
void castling() {}
