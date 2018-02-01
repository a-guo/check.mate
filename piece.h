#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece {
  int x, int y;
 public:
   Piece(int x, int y) virtual;
   ~Piece() virtual;
   void setPiece(int x, int y) virtual;
   std::vector getPiece(Piece piece) virtual;
};

#endif
