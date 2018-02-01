#include "king.h"

using namespace std;

King::King(int x, int y) : x(x), y(y) {};

King::~King() {
  return;
}

void King::setPiece(int x, int y);

std::vector King::getPiece(Piece piece);
