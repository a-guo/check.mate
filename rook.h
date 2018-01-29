#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : class Piece {
 public:
   Rook(int x, int y) override;
   ~Rook() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
