#include "knight.h"
#include <cstdlib>

using namespace std;

Knight::Knight(char type, int row, int col, Player* p, Board* theBoard) :
              Piece(type, row, col, p, theBoard) {}

bool Knight::validMove(int row, int col);

bool Knight::tryNextMove() {
  return (validMove(row + 2, col + 1) ||
          validMove(row - 2, col + 1) ||
          validMove(row + 2, col - 1) ||
          validMove(row - 2, col - 1) ||
          validMove(row + 1, col + 2) ||
          validMove(row + 1, col - 2) ||
          validMove(row - 1, col + 2) ||
          validMove(row - 1, col - 2));
}

void Knight::check(Player* opp);

void Knight::uncheck(Player* opp, int row, int col);

void Knight::notifyDisplay(Textdisplay& t) {}
void Knight::upgrade() {}
