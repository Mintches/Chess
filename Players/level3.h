#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include "../board.h"
using namespace std;

class Level3: public Computer {
    Move getMove(Board *board, Colour player) const override;
};

#endif
