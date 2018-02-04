#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <sstream>
#include "window.h"

class TextDisplay {
  char** theDisplay;
  const int boardSize;
  Xwindow *w;
 public:
   TextDisplay(int n);
   void resetDisplay();
   void notify(int iRow, int iCol, int fRow, int fCol, char type);

   ~TextDisplay();

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
