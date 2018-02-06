#include "human.h"
#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Human::Human(Board* theBoard, int numOpp, int bottomLine, int playerNum);;
void Human::addPiece(Piece *p, int row, int col);
void Human::removePiece(int row, int col);
bool Human::move();
