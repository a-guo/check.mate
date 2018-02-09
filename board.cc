#include "board.h"
#include "textdisplay.h"
#include "trashbin.h" // is this even called trashbin?
#include "player.h"
#include "piece.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

const int BOARD_SIZE = 8;
const int MAX_PIECE = 32;

Board::Board(int maxPlayer) : maxPlayer(maxPlayer), numPlayer(0), currentPlayer(0) {
  theBoard = new Piece** [BOARD_SIZE];
  theDisplay = new Textdisplay[BOARD_SIZE];
  placed = new bool* [BOARD_SIZE];
  players = new Player* [maxPlayer];
  theTrash = new Trash [MAX_PIECE];
  scores = new int(2);
  scores[0] = 0;
  scores[1] = 0;
  for(int i = 0; i < BOARD_SIZE; i++) {
    theBoard[i] = new Piece* [BOARD_SIZE];
    placed[i] = new bool [BOARD_SIZE];
    players[i] = NULL;

    for(int j = 0; j < BOARD_SIZE; j++) {
      theBoard[i][j] = NULL;
      placed[i][j] = false;
    }
  }
}

// default initialize to 2 players
void Board::defaultInit(Player* p1, Player* p2) {
  theDisplay->resetDisplay();
  players[0] = p1;
  players[1] = p2;
  numPlayer = 2;
  p1->addOpp(p2);
  p2->addOpp(p1);
  theBoard = new Piece** [BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    theBoard[i] = new Piece* [BOARD_SIZE];
    for (int j = 0; j < BOARD_SIZE; j++) {
      theBoard[i][j] = NULL;
      place[i][j] = false;
    }
  }
  // black initialization
  setPiece('r', 0, 0);
  setPiece('n', 0, 1);
  setPiece('b', 0, 2);
  setPiece('q', 0, 3);
  setPiece('k', 0, 4);
  setPiece('b', 0, 5);
  setPiece('n', 0, 6);
  setPiece('r', 0, 7);
  for (int i = 0; i < BOARD_SIZE; i++) {
    setPiece('p', 1, i);
  }

  // white initialization
  setPiece('R', BOARD_SIZE - 1, 0);
  setPiece('N', BOARD_SIZE - 1, 1);
  setPiece('B', BOARD_SIZE - 1, 2);
  setPiece('Q', BOARD_SIZE - 1, 3);
  setPiece('K', BOARD_SIZE - 1, 4);
  setPiece('B', BOARD_SIZE - 1, 5);
  setPiece('N', BOARD_SIZE - 1, 6);
  setPiece('R', BOARD_SIZE - 1, 7);
  for (int i = 0; i < BOARD_SIZE; i++) {
    setPiece('P', BOARD_SIZE - 2, i);
  }
}

// board is notified iff piece on board has movement
// aka a player has done the move
void Board::notify(int iRow, int iCol, int fRow, int fCol) {
  // if there is a piece there, delete it
  delPiece(fRow, fCol);
  // move the required piece
  theBoard[fRow][fCol] = theBoard[iRow][iCol];
  theBoard[iRow][iCol] = NULL;
  theDisplay->notify(iRow, iCol, fRow, fCol, theBoard[fRow][fCol]->getType());
}

void Board::addPlayer(Player* p) {
  players[numPlayer] = p;
  numPlayer++;
}

void Board::setPiece(char type, int row, int col);

Piece* Board::getPiece(int row, int col) {
  return theBoard[row][col];
}

void Board::delPiece(int row, int col) {
  if(theBoard[row][col] != NULL) {
    // notify all players that this will be removed
    notifyPlayer(row, col);
    // throw it in trash, and set to NULL
    theTrash->dump(theBoard[row][col]);
    theBoard[row][col] = NULL;
    placed[row][col] = false;
    theDisplay->notify(row, col, -1, -1, 'a');
  }
}

bool Board::isPlaced(int row, int col) {
  return placed[row][col];
}

void Board::setPlaced(int row, int col, bool value) {
  placed[row][col] = value;
}

void Board::notifyPlayer(int row, int col) {
  for(int i = 0; i < numPlayer; i++) {
    players[i]->removePiece(row, col);
  }
}

Player* Board::getPlayer() {
  return players[currentPlayer];
}

int Board::getTurn() {
  return currentPlayer;
}

bool Board::checkForStart() {
  for(int i = 0; i < numPlayer; i++) {
    // check each player has a king
    if (players[i]->getKing() == NULL) {
      return false;
    }
    // check for bottom line pawns
    if (players[i]->bottomLinePawn()) {
      return false;
    }
    // check players aren't in check
    if (players[i]->getChecked()) {
      return false;
    }
  }
}

void Board::nextTurn() {
  currentPlayer = (currentPlayer + 1) % numPlayer;
}

void Board::setTurn(int tNum) {
  currentPlayer = tNum;
}

void Board::addScore() {
  // everyone except current player gets a point
  for(int i = 0; i < numPlayer; i++) {
    if (i != currentPlayer) {
      scores[i]++;
    }
  }
}

void Board::printScore() {
  for (int i = 0; i < numPlayer; i++) {
    cout << "Player " << i + 1 << ": " << scores[i] << endl;
  }
}

Board::~Board() {
  theTrash->emptyTrash();
  for(int i = 0; i < BOARD_SIZE; i++) {
    for(int j = 0; j < BOARD_SIZE; j++) {
      delete theBoard[i][j];
    }
    delete [] theBoard[i];
  }
  delete [] theBoard;
}

ostream &Board::operator<<(ostream &out, const Board &b) {
  out << *(b.theDisplay);
  return out;
}
