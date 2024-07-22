#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <random>

#include "../board.h"
#include "computer.h"
using namespace std;

class Level1: public Computer {
    string getMove(Board *board, Colour player) const override;
};

#endif
