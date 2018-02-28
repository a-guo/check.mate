#include "trashbin.h"
#include <stdlib.h>

TrashBin(int capacity);
void dump(Piece* garbage);
void emptyBin();
Piece* recover(Piece* p);
