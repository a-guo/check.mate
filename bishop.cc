#include "bishop.h"

using namespace std;

Bishop::Bishop(int x, int y) : x(x), y(y) {};

Bishop::~Bishop() {
  return;
}

void Bishop::setPiece(int x, int y);

std::vector Bishop::getPiece(Piece piece);
