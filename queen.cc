#include "queen.h"

using namespace std;

Queen::Queen(int x, int y) : x(x), y(y) {};

Queen::~Queen() {
  return;
}

void Queen::setPiece(int x, int y);

std::vector Queen::getPiece(Piece piece);
