#include "bishop.h"
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(char type, int row, int col, Player* p, Board* theBoard)
              : Piece(type, row, col, p, theBoard) {}
              
bool Bishop::validMove(int row, int col);
bool Bishop::tryNextMove();
void Bishop::check(Player* opp);
void Bishop::uncheck(Player* opp, int row, int col);

void Bishop::notifyDisplay(Textdisplay& t) {}

void Bishop::upgrade() {}
