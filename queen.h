#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : class Piece {
 public:
   Queen(int x, int y) override;
   ~Queen() override;
   void setPiece(int x, int y) override;
   std::vector getPiece(Piece piece) override;
};

#endif
