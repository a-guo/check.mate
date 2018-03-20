#include "knight.h"
#include <cstdlib>

using namespace std;

Knight::Knight(char type, int row, int col, Player* p, Board* theBoard) :
              Piece(type, row, col, p, theBoard) {}

bool Knight::validMove(int row, int col) {
  
}

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

void Knight::check(Player* opp) {
  if (row + 2 < GRID_SIZE && col + 1 < GRID_SIZE)
    opp->check(row + 2, col + 1);
  if (row + 2 < GRID_SIZE && col - 1 > 0)
    opp->check(row + 2, col - 1);
  if (row - 2 > 0 && col + 1 < GRID_SIZE)
    opp->check(row - 2, col + 1);
  if (row - 2 > 0 && col - 1 > 0)
    opp->check(row - 2, col - 1);
  if (row + 1 < GRID_SIZE && col + 2 < GRID_SIZE)
    opp->check(row + 1, col + 2);
  if (row + 1 < GRID_SIZE && col - 2 > 0)
    opp->check(row + 1, col - 2);
  if (row - 1 > 0 && col + 2 > GRID_SIZE)
    opp->check(row - 1, col + 2);
  if (row - 1 > 0 && col - 2 > 0)
    opp->check(row - 1, col - 2);
}

void Knight::uncheck(Player* opp, int row, int col) {
  if (row + 2 < GRID_SIZE && col + 1 < GRID_SIZE)
    opp->uncheck(row + 2, col + 1);
  if (row + 2 < GRID_SIZE && col - 1 > 0)
    opp->uncheck(row + 2, col - 1);
  if (row - 2 > 0 && col + 1 < GRID_SIZE)
    opp->uncheck(row - 2, col + 1);
  if (row - 2 > 0 && col - 1 > 0)
    opp->uncheck(row - 2, col - 1);
  if (row + 1 < GRID_SIZE && col + 2 < GRID_SIZE)
    opp->uncheck(row + 1, col + 2);
  if (row + 1 < GRID_SIZE && col - 2 > 0)
    opp->uncheck(row + 1, col - 2);
  if (row - 1 > 0 && col + 2 > GRID_SIZE)
    opp->uncheck(row - 1, col + 2);
  if (row - 1 > 0 && col - 2 > 0)
    opp->uncheck(row - 1, col - 2);
}

void Knight::notifyDisplay(TextDisplay& t) {}
void Knight::upgrade() {}
