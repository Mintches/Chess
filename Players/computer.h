#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

#include "player.h"
#include "../board.h"
#include "../colour.h"

using namespace std;

class Computer: public Player {
    public:
        virtual string getMove() const override;
};

#endif
