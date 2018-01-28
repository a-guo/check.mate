#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Board {
    std::shared_ptr<grid> g;
    unsigned int score;
    std::vector<history_info> history; // history of fixed block's info
    unsigned int level;
    bool random;
    unsigned int highscore;
    unsigned int noClear; // the # of blocks placed without clearing a row
    std::string sequence;
    std::string randomSeq;
    unsigned int startLevel;
    Block current;
    Block next;
    std::queue<char> seq;
    std::queue<char> randSeq;
    Block generateBlock();
    bool shouldLock();
    void lockBlock(); // Locks the current block in place so that it will not be able to move or rotate any longer
    void GameOver();
    void calculateScore(unsigned int linesCleared);
    void removeRow(std::vector<unsigned int>);
    void dropStarBlock();
public:
    Board();
    ~Board();


};

#endif
