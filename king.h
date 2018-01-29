#ifndef KING_H
#define KING_H

#include "piece.h"

class King : class Piece {
 public:
   King(int x, int y) override;
   ~King() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
