#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];
  int width, height;
public:
  Xwindow(int width=500, int height=500); // constructor displays Window
  ~Xwindow(); // destructor destroys Window

  // available colours
  enum {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown};

  // draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // draws a string
  void drawString(int x, int y, std::string msg, int colour=Black);

  // draws a big string
  void drawBigString(int x, int y, std::string msg, int colour=Black);

  // prints first 10,000 available fonts
  void showAvailableFonts();
};

#endif
