#ifndef BOARD_H
#define BOARD_H


#include <vector>
#include <string>

class Piece;

class Board {
    std::vector<std::vector<string>> theBoard;
    std::vector<Piece> pieces;
public:
    Board();
    ~Board();
};

#endif
