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

int maxPlayer;
int numPlayer;
int currentPlayer;
int* scores;
Piece*** theBoard;
bool** placed;
Textdisplay* theDisplay;
Player** players;
Trash* theTrash;

Board::Board(int maxPlayer);
// default initialize to 2 players
void Board::defaultInit(Player* p1, Player* p2);
void Board::notify(int iRow, int iCol, int fRow, int fCol);
void Board::addPlayer(Player* p);
void Board::setPiece(char type, int row, int col);
Piece* Board::getPiece(int row, int col);
void Board::delPiece(int row, int col);
bool Board::isPlaced(int row, int col);
void Board::setPlaced(int row, int col, bool value);
void Board::notifyPlayer(int row, int col);
Player* Board::getPlayer();
int Board::getTurn();
bool Board::checkForStart();
void Board::nextTurn();
void Board::setTurn(int tNum);
void Board::addScore();
void Board::printScore();

Board::~Board();

ostream &Board::operator<<(ostream &out, const Board &b);
