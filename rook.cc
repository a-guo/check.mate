#include "rook.h"

using namespace std;

Rook::Rook(int x, int y) : x(x), y(y) {};

Rook::~Rook() {
  return;
}

void Rook::setPiece(int x, int y);

std::vector Rook::getPiece(Piece piece);
