#include "textdisplay.h"

using namespace std;

~TextDisplay();

TextDisplay(std::shared_ptr<Board> theBoard);

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
