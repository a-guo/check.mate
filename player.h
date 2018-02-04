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
  int** Checked;
  Player(Board* theBoard, int maxOpp, int bottomLine, int playerNum);
  virtual bool move() = 0;
  virtual void addPiece(Piece *p, int row, int col) = 0;
  virtual void removePiece(int row, int col) = 0;

  int getPNum();
  void reCalc();
  void clearChecked();
  int getScore(int row, int col);
  void check(int row, int col);
  void uncheck(int row, int col);
  bool getChecked();

  void notifyBoard(int iRow, int iCol, int fRow, int fCol);
  void addOpp(Player* opp);
  bool isChecked(int row, int col);
  bool isPlaced(int row, int col);
  Player* getOpp(int pNum);
  Piece* getKing();

  bool bottomLinePawn();
  void checkOpps(Piece* p);
  void uncheckOpps(Piece* p);
  ~Player();
};
#endif
