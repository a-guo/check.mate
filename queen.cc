#include "queen.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Queen::Queen(char type, int row, int col, Player* p, Board* theBoard)
            : Piece(type, row, col, p, theBoard) {}

bool Queen::validMove(int row, int col);
bool Queen::tryNextMove();
void Queen::check(Player* opp);
void Queen::uncheck(Player* opp, int row, int col);

void Queen::notifyDisplay(Textdisplay& t) {}
void Queen::upgrade() {}
