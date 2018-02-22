#include "king.h"
#include <cstdlib>

using namespace std;

int abs(int x) {
  if (x < 0) return x;
  return x;
}

King::King(char type, int row, int col, Player* p, Board* theBoard);
bool King::validMove(int row, int col);
bool King::tryNextMove();
void King::check(Player* opp);
void King::uncheck(Player* opp, int row, int col);
void King::notifyDisplay(Textdisplay& t);
void King::upgrade();

void castling();
