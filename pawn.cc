#include "pawn.h"

using namespace std;

Pawn::Pawn(int x, int y) : x(x), y(y) {};

Pawn::~Pawn() {
  return;
}

void Pawn::setPiece(int x, int y);

std::vector Pawn::getPiece(Piece piece);
