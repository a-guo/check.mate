#include "player.h"
#include "human.h"
#include "board.h"
#include "trashbin.h"
#include "piece.h"
#include "textdisplay.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
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
      if (startGame) {
        cout << "Sorry, the game has started, you cannot setup the board"<< endl;
        continue;
      }
      Player* pp1 = new Human(game, MAX_PLAYER, 0, 0);
      Player* pp2 = new Human(game, MAX_PLAYER, GRID_SIZE - 1, 1);
      pp1->addOpp(pp2);
      pp2->addOpp(pp1);
      game->addPlayer(pp1);
      game->addPlayer(pp2);
      while (cin >> opp) {
        if (opp == "+") {
          char type, colc;
          int col, row;
          cin >> type >> colc >> row;
          col = colc - 'a';
          game->setPiece(type, GRID_SIZE - row, col);
          cout << *game;
        } else if (opp == "-") {
          char colc;
          int col, row;
          cin >> colc >> row;
          col = colc - 'a';
          game->delPiece(GRID_SIZE - row, col);
          cout << *game;
        } else if (opp == "=") {
          string colour;
          cin >> colour;
          if (colour == "white") {
            game->setTurn(0);
          } else if (colour == "black") {
            game->setTurn(1);
          }
        } else if (opp == "done") {
          if (!game->checkForStart()) {
            cout << "Not a valid start! Please check your board!" << endl;
            cout << *game;
          } else {
            break;
          }
        }
      }

    }
    else if (op == "resign") {
      if (startGame) {
        game->nextTurn();
        game->addScore();
      } else {
        cout << "A game has not been established yet" << endl;
      }
    }
    else if (op == "print") {
      cout << *game;
    }
    else if (op == "try") {
      char col;
      int row;
      cin >> col >> row;
      cout << game->getPiece(GRID_SIZE - row, col - 'a')->tryNextMove() << endl;
    }
    else if (op == "check") {
      char col;
      int row;
      cin >> col >> row;
      cout << game->getPlayer()->isChecked(GRID_SIZE - row, col - 'a') << endl;
    }
  }
}
