#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "player.h"
#include "../board.h"
using namespace std;

class Computer: public Player {
    public:
        virtual string getMove(Board board) const override;
};

#endif
