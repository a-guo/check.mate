#include "knight.h"

using namespace std;

Knight::Knight (int x, int y) : x(x), y(y) {};

Knight::~Knight() {
  return;
}

void Knight::setPiece(int x, int y);

std::vector Knight::getPiece(Piece piece);
