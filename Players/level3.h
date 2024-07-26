#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include <memory>
#include "../board.h"
using namespace std;

class Square; // forward declaration

class Level3: public Computer {
    Move getMove(Board *board, Colour player) const override;
};

bool willCapture(Board *board, Colour oppPlayer, Colour currPlayer, shared_ptr<Square> s);

#endif
