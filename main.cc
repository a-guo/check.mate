#include "player.h"
#include "board.h"
#include "trashbin.h"
#include "piece.h"
#include "textdisplay.h"
#include <iostream>
#include <cstdlib>
#include <string>

#include <time.h>

using namespace std;

const int MAX_PLAYER = 2;
const int BOARD_SIZE = 8;

int main() {
  Board* game = new Board(MAX_PLAYER);
  string op;
  bool startGame = false;

  srand(time(NULL));

  while (cin >> op) {
    if (op == "game") {
      string p1;
      string p2;
      Player* pp1;
      Player* pp2;
      cin >> p1;
      // white Player
      if (p1 == "human") {
        pp1 = new Human (game, MAX_PLAYER, 0, 0);
      } else {
        int level;
        cin >> level;
        switch(level)
        {
          case 1:
            pp1 = new Level1(game, MAX_PLAYER, 0, 0);
            break;
          case 2:
            pp1 = new Level2(game, MAX_PLAYER, 0, 0);
            break;
          case 3:
            pp1 = new Level3(game, MAX_PLAYER, 0, 0);
          default:
            break;
        }
      }
      // black player
      cin >> p2;
      if (p2 == "human") {
        pp2 = new Human (game, MAX_PLAYER, BOARD_SIZE - 1, 1);
      } else {
        int level;
        cin >> level;
        switch(level)
        {
          case 1:
            pp2 = new Level1(game, MAX_PLAYER, GRID_SIZE - 1, 1);
            break;
          case 2:
            pp2 = new Level2(game, MAX_PLAYER, GRID_SIZE - 1, 1);
            break;
          case 3:
            pp2 = new Level3(game, MAX_PLAYER, GRID_SIZE - 1, 1);
          default:
            break;
        }
      }

      game->defaultInit(pp1, pp2);
      startGame = true;
      cout << *game;
    }
    else if (op == "move") {
      while (!game->getPlayer()->move()) {
        cout << "Invalid move, please re-enter coordinates" << endl;
      }
      game->nextTurn();
      // player got checked
      if (game->getPlayer()->getChecked()) {
        cout << *game;
        cout << "Player" << game->getTurn() + 1 << " lost!" << endl;
        game->addScore();
        game->printScore();

        string response;
        cout << "another game? (y/n):";
        cin >> response;
        startGame = false;
        if (response == "n") return 1;
        else {
          cout << "enter game [player1] [player2] to restart!" << endl;
          //startGame = false;
        }
      }
      startGame = true;
    }
    else if (op == "setup") {
      string opp;

    }
  }
}
