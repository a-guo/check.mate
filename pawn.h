#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : class Piece {
 public:
   Pawn(int x, int y) override;
   ~Pawn() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
