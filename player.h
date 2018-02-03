#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Piece;

// pure abstract class Player
class Player {
protected:
  int playerNum; // which player I am
  static int numKing;
  int ** values;
  int bottomLine;
  int maxOpp;
  int numOpp;
  int numPiece;
  Player** Opps; // oops will include this
  Piece*** myPiece;
  Piece** pList;
  Piece* theKing;
  Board* theBoard;
public:
  
}
