#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : class Piece {
 public:
   Bishop(int x, int y) override;
   ~Bishop() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
