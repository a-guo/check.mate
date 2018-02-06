#include "engine.h"
#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Engine::Engine(Board* theBoard, int numOpp, int bottomLine, int playerNum);
void Engine::addPiece(Piece *p, int row, int col);
void Engine::removePiece(int row, int col);
