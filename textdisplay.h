#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>

class Board;

class TextDisplay {
  std::shared_ptr<Board> theBoard;
  std::vector<std::vector<char>> theDisplay;
 public:
    ~TextDisplay();
    TextDisplay(std::shared_ptr<Board> theBoard);

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
