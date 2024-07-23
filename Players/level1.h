#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <random>

#include "computer.h"
using namespace std;

class Level1: public Computer {
    Move getMove(Board *board, Colour player) const override;
};

#endif
