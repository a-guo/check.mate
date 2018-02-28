 #ifndef TRASHBIN_H
 #define TRASHBIN_H

 class Piece;

 class TrashBin {
   Piece** theBin;
   int numTrash;
   int capacity;
 public:
   TrashBin(int capacity);
   void dump(Piece* garbage);
   void emptyBin();
   Piece* recover(Piece* p);
 };

 #endif
