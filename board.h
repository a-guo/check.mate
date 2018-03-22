#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include "trashbin.h"
#include "textdisplay.h"
#include "window.h"

class Piece;
class Player;

class Board {
    int numPlayer;
    int currentPlayer;
    int* scores;
    Piece*** theBoard;
    bool** placed;
    TextDisplay* theDisplay;
    Player** players;
    TrashBin* theTrash;
public:
    Board(int maxPlayer);
    // default initialize to 2 players
    void defaultInit(Player* p1, Player* p2);
    void notify(int iRow, int iCol, int fRow, int fCol);
    void addPlayer(Player* p);
    void setPiece(char type, int row, int col);
    Piece* getPiece(int row, int col);
    void delPiece(int row, int col);
    bool isPlaced(int row, int col);
    void setPlaced(int row, int col, bool value);
    void notifyPlayer(int row, int col);
    Player* getPlayer();
    int getTurn();
    bool checkForStart();
    void nextTurn();
    void setTurn(int tNum);
    void addScore();
    void printScore();

    ~Board();

    friend std::ostream& operator<<(std::ostream &out, const Board &b);
};

#endif
