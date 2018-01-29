#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : class Piece {
 public:
   Knight(int x, int y) override;
   ~Knight() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
