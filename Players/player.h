#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "../board.h"
#include "../move.h"
#include "../colour.h"

using namespace std;

class Board; // forward declaration

class Player {
public:
    virtual Move getMove(Board *board, Colour player) const = 0;

    virtual ~Player() = default;
};

#endif
