#ifndef LEVEL4_H
#define LEVEL4_H

#include <string>
#include "../board.h"
using namespace std;

class Level4: public Computer {
    Move getMove(Board *board, Colour player) const override;
    //string getMove(Board *board, int depth) const override;
};

int minimax(Board *board, int depth, int alpha, int beta, bool mxPlayer);
void printBoard(Board *board);

#endif
